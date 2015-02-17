$NetBSD: patch-etc_exabgp_processes_healthcheck.py,v 1.1 2015/02/17 13:41:36 he Exp $

Also match interface alias addresses, and spaces at the front
are optional, particularly after "strip"...
Also, provide more debugging output.

--- etc/exabgp/processes/healthcheck.py.orig	2014-03-25 19:39:16.000000000 +0000
+++ etc/exabgp/processes/healthcheck.py
@@ -1,4 +1,4 @@
-#!/usr/bin/env python
+#!/usr/pkg/bin/python2.7
 
 """Healthchecker for exabgp.
 
@@ -210,16 +210,19 @@ def loopback_ips():
         cmd = subprocess.Popen("/sbin/ip -o address show dev lo".split(), shell=False, stdout=subprocess.PIPE)
     else:
         # Try with ifconfig
-        ipre = re.compile(r"^\s+inet6?\s+(?P<ip>[\da-f.:]+)\s+(?:netmask 0x(?P<netmask>[0-9a-f]+)|prefixlen (?P<mask>\d+)).*")
+        ipre = re.compile(r"^\s*inet6?\s+(alias )?(?P<ip>[\da-f.:]+)\s+(?:netmask 0x(?P<netmask>[0-9a-f]+)|prefixlen (?P<mask>\d+)).*")
         cmd = subprocess.Popen("/sbin/ifconfig lo0".split(), shell=False, stdout=subprocess.PIPE)
     for line in cmd.stdout:
         line = line.decode("ascii", "ignore").strip()
         mo = ipre.match(line)
         if not mo:
+	    logger.debug("Skipping line: {0}".format(line))
             continue
         ip = ip_address(mo.group("ip"))
         if not ip.is_loopback:
             addresses.append(ip)
+	else:
+	    logger.debug("Skipping loopback address: {0}".format(ip))
     if not addresses:
         raise RuntimeError("No loopback IP found")
     logger.debug("Loopback addresses: {0}".format(addresses))
