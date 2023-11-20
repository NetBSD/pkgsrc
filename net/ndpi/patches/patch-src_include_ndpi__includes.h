$NetBSD: patch-src_include_ndpi__includes.h,v 1.2 2023/11/20 17:57:31 adam Exp $

Same case with SunOS.

--- src/include/ndpi_includes.h.orig	2023-10-23 09:45:30.000000000 +0000
+++ src/include/ndpi_includes.h
@@ -50,7 +50,7 @@
 #include <netinet/udp.h>
 #endif
 
-#if !defined __APPLE__ && !defined __FreeBSD__ && !defined __NetBSD__ && !defined __OpenBSD__
+#if !defined __APPLE__ && !defined __FreeBSD__ && !defined __NetBSD__ && !defined __OpenBSD__ && !defined __sun
 #include <endian.h>
 #include <byteswap.h>
 
