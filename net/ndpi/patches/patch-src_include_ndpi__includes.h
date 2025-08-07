$NetBSD: patch-src_include_ndpi__includes.h,v 1.3 2025/08/07 05:03:08 adam Exp $

Same case with SunOS.

--- src/include/ndpi_includes.h.orig	2025-04-28 06:58:26.000000000 +0000
+++ src/include/ndpi_includes.h
@@ -45,7 +45,7 @@
 #include <sys/socket.h>
 #include <netinet/in.h>
 
-#if !defined __APPLE__ && !defined __FreeBSD__ && !defined __NetBSD__ && !defined __OpenBSD__
+#if !defined __APPLE__ && !defined __FreeBSD__ && !defined __NetBSD__ && !defined __OpenBSD__ && !defined __sun
 #include <endian.h>
 #include <byteswap.h>
 
