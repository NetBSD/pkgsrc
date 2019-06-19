$NetBSD: patch-src_network_network.cc,v 1.1 2019/06/19 15:50:52 schmonz Exp $

Fix OS X clang build. Via FreeBSD Ports, so probably fixes FreeBSD too.

--- src/network/network.cc.orig	2017-07-22 21:14:53.000000000 +0000
+++ src/network/network.cc
@@ -335,7 +335,7 @@ bool Connection::try_bind( const char *a
       }
     }
 
-    if ( bind( sock(), &local_addr.sa, local_addr_len ) == 0 ) {
+    if ( ::bind( sock(), &local_addr.sa, local_addr_len ) == 0 ) {
       set_MTU( local_addr.sa.sa_family );
       return true;
     } else if ( i == search_high ) { /* last port to search */
