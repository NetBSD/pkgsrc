$NetBSD: patch-src_include_ndpi__includes.h,v 1.1.2.2 2017/06/21 18:39:02 bsiegert Exp $

Same case with SunOS.

--- src/include/ndpi_includes.h.orig	2016-06-27 19:31:24.000000000 +0000
+++ src/include/ndpi_includes.h
@@ -46,7 +46,7 @@
 #include <netinet/tcp.h>
 #include <netinet/udp.h>
 
-#if !defined __APPLE__ && !defined __FreeBSD__ && !defined __NetBSD__ && !defined __OpenBSD__
+#if !defined __APPLE__ && !defined __FreeBSD__ && !defined __NetBSD__ && !defined __OpenBSD__ && !defined __sun
 #include <endian.h>
 #include <byteswap.h>
 
