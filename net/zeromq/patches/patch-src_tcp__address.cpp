$NetBSD: patch-src_tcp__address.cpp,v 1.1 2015/09/30 10:45:10 fhajny Exp $

Back port build fix for SunOS.
From https://github.com/zeromq/libzmq/pull/1440

--- src/tcp_address.cpp.orig	2015-06-15 09:43:08.000000000 +0000
+++ src/tcp_address.cpp
@@ -86,7 +86,7 @@ int zmq::tcp_address_t::resolve_nic_name
     //  Find the interface with the specified name and AF_INET family.
     bool found = false;
     lifreq *ifrp = ifc.lifc_req;
-    for (int n = 0; n < (int) (ifc.lifc_len / sizeof lifreq);
+    for (int n = 0; n < (int) (ifc.lifc_len / sizeof (lifreq));
           n ++, ifrp ++) {
         if (!strcmp (nic_, ifrp->lifr_name)) {
             rc = ioctl (fd, SIOCGLIFADDR, (char*) ifrp);
