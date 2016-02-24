$NetBSD: patch-tgl_tl-parser_portable__endian.h,v 1.1 2016/02/24 02:29:44 khorben Exp $

Fix build on NetBSD

--- tgl/tl-parser/portable_endian.h.orig	2015-10-17 13:33:25.000000000 +0000
+++ tgl/tl-parser/portable_endian.h
@@ -49,6 +49,10 @@
 
 #	include <sys/endian.h>
 
+#elif defined(__NetBSD__)
+
+#	include <sys/endian.h>
+
 #elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
 
 #	include <sys/endian.h>
