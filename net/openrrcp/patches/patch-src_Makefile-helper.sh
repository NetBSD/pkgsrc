$NetBSD: patch-src_Makefile-helper.sh,v 1.1 2020/04/28 15:22:43 manu Exp $

Add runtime search path for libdnet

Also, this software crashses with -O2 and works with -g, which does not
helps for debugging.

--- src/Makefile-helper.sh.orig	2020-04-27 17:26:24.128386613 +0200
+++ src/Makefile-helper.sh	2020-04-27 17:17:53.896676336 +0200
@@ -7,9 +7,9 @@
     exit;
 fi;
 
 if test "$sys" = "NetBSD"; then
-    echo -n "-s -Wall -O2 -ldnet -lpcap -I/usr/pkg/include -L/usr/pkg/lib"
+    echo -n "-s -Wall -g -ldnet -lpcap -I${PREFIX}/include -L${PREFIX}/lib -R${PREFIX}/lib"
     exit;
 fi;
 
 if test "$sys" = "FreeBSD"; then
