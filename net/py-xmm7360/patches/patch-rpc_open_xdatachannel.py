$NetBSD: patch-rpc_open_xdatachannel.py,v 1.1 2020/07/27 14:11:16 jdolecek Exp $

--- rpc/open_xdatachannel.py.orig	2020-01-15 00:30:10.000000000 +0000
+++ rpc/open_xdatachannel.py
@@ -4,11 +4,18 @@ import logging
 # must do this before importing pyroute2
 logging.basicConfig(level=logging.DEBUG)
 
-import rpc
+from xmm7360 import rpc
 import binascii
 import time
 import sys
-from pyroute2 import IPRoute
+import os
+try:
+	from pyroute2 import IPRoute
+	ipr = IPRoute()
+	if not callable(getattr(ipr, 'link_lookup')):
+		ipr = None
+except:
+	ipr = None
 
 import configargparse
 
@@ -29,8 +36,6 @@ cfg = parser.parse_args()
 
 r = rpc.XMMRPC()
 
-ipr = IPRoute()
-
 r.execute('UtaMsSmsInit')
 r.execute('UtaMsCbsInit')
 r.execute('UtaMsNetOpen')
@@ -72,26 +77,30 @@ logging.info("DNS server(s): " + ', '.jo
 
 # For some reason, on IPv6 networks, the GetNegIpAddrReq call returns 8 bytes of the IPv6 address followed by our 4 byte IPv4 address.
 # use the last nonzero IP
+ip_addr = None
 for addr in ip_values[::-1]:
     if addr.compressed != '0.0.0.0':
         ip_addr = addr.compressed
         break
 
-idx = ipr.link_lookup(ifname='wwan0')[0]
-
-ipr.flush_addr(index=idx)
-ipr.link('set',
-        index=idx,
-        state='up')
-ipr.addr('add',
-        index=idx,
-        address=ip_addr)
-
-if not cfg.nodefaultroute:
-    ipr.route('add',
-            dst='default',
-            priority=cfg.metric,
-            oif=idx)
+if not ip_addr:
+	logging.info('No valid IP address, exiting')
+	sys.exit(1)
+
+if ipr:
+	idx = ipr.link_lookup(ifname='wwan0')[0]
+
+	ipr.flush_addr(index=idx)
+	ipr.link('set', index=idx, state='up')
+	ipr.addr('add', index=idx, address=ip_addr)
+
+	if not cfg.nodefaultroute:
+	    ipr.route('add', dst='default',
+	            priority=cfg.metric,
+	            oif=idx)
+else:
+	os.system('ifconfig wwan0 %s' % (ip_addr))
+	os.system('route add default -iface %s' % (ip_addr))
 
 # Add DNS values to /etc/resolv.conf
 if not cfg.noresolv:
