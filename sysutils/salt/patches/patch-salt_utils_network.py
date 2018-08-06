$NetBSD: patch-salt_utils_network.py,v 1.7 2018/08/06 05:01:26 tpaul Exp $

Handle new ifconfig output on NetBSD 8.0

Upstream issue: https://github.com/saltstack/salt/issues/48856
Upstream pull request: https://github.com/saltstack/salt/pull/48926

--- salt/utils/network.py.orig	2018-06-27 16:04:57.000000000 +0000
+++ salt/utils/network.py
@@ -15,6 +15,7 @@ import platform
 import random
 import subprocess
 from string import ascii_letters, digits
+from salt.utils.versions import LooseVersion
 
 # Import 3rd-party libs
 from salt.ext import six
@@ -862,6 +863,83 @@ def linux_interfaces():
     return ifaces
 
 
+def _netbsd_interfaces_ifconfig(out):
+    '''
+    Uses ifconfig to return a dictionary of interfaces with various information
+    about each (up/down state, ip address, netmask, and hwaddr)
+    '''
+    ret = dict()
+
+    piface = re.compile(r'^([^\s:]+)')
+    pmac = re.compile('.*?address: ([0-9a-f:]+)')
+
+    pip = re.compile(r'.*?inet [^\d]*(.*?)/([\d]*)\s')
+    pip6 = re.compile('.*?inet6 ([0-9a-f:]+)%([a-zA-Z0-9]*)/([\d]*)\s')
+
+    pupdown = re.compile('UP')
+    pbcast = re.compile(r'.*?broadcast ([\d\.]+)')
+
+    groups = re.compile('\r?\n(?=\\S)').split(out)
+    for group in groups:
+        data = dict()
+        iface = ''
+        updown = False
+        for line in group.splitlines():
+            miface = piface.match(line)
+            mmac = pmac.match(line)
+            mip = pip.match(line)
+            mip6 = pip6.match(line)
+            mupdown = pupdown.search(line)
+            if miface:
+                iface = miface.group(1)
+            if mmac:
+                data['hwaddr'] = mmac.group(1)
+            if mip:
+                if 'inet' not in data:
+                    data['inet'] = list()
+                addr_obj = dict()
+                addr_obj['address'] = mip.group(1)
+                mmask = mip.group(2)
+                if mip.group(2):
+                    addr_obj['netmask'] = cidr_to_ipv4_netmask(mip.group(2))
+                mbcast = pbcast.match(line)
+                if mbcast:
+                    addr_obj['broadcast'] = mbcast.group(1)
+                data['inet'].append(addr_obj)
+            if mupdown:
+                updown = True
+            if mip6:
+                if 'inet6' not in data:
+                    data['inet6'] = list()
+                addr_obj = dict()
+                addr_obj['address'] = mip6.group(1)
+                mmask6 = mip6.group(3)
+                addr_obj['scope'] = mip6.group(2)
+                addr_obj['prefixlen'] = mip6.group(3)
+                data['inet6'].append(addr_obj)
+        data['up'] = updown
+        ret[iface] = data
+        del data
+    return ret
+
+def netbsd_interfaces():
+    '''
+    Obtain interface information for NetBSD >= 8 where the ifconfig
+    output diverged from other BSD variants (Netmask is now part of the
+    address)
+    '''
+    # NetBSD versions prior to 8.0 can still use linux_interfaces()
+    if LooseVersion(os.uname()[2]) < LooseVersion('8.0'):
+        return linux_interfaces()
+
+    ifconfig_path = salt.utils.path.which('ifconfig')
+    cmd = subprocess.Popen(
+        '{0} -a'.format(ifconfig_path),
+        shell=True,
+        stdout=subprocess.PIPE,
+        stderr=subprocess.STDOUT).communicate()[0]
+    return _netbsd_interfaces_ifconfig(salt.utils.stringutils.to_str(cmd))
+
 def _interfaces_ipconfig(out):
     '''
     Returns a dictionary of interfaces with various information about each
@@ -963,10 +1041,11 @@ def interfaces():
     '''
     if salt.utils.platform.is_windows():
         return win_interfaces()
+    elif salt.utils.platform.is_netbsd():
+        return netbsd_interfaces()
     else:
         return linux_interfaces()
 
-
 def get_net_start(ipaddr, netmask):
     '''
     Return the address of the network
