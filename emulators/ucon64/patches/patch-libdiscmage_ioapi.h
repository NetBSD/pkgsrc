$NetBSD: patch-libdiscmage_ioapi.h,v 1.1 2020/12/05 13:16:36 wiz Exp $

OF is not defined in zlib.h on all systems.
From upstream.

--- libdiscmage/ioapi.h.orig	2016-03-03 13:55:44.000000000 +0000
+++ libdiscmage/ioapi.h
@@ -35,6 +35,11 @@
 extern "C" {
 #endif
 
+// On NetBSD and Gentoo, OF is not defined in zconf.h, which is included by zlib.h.
+#ifndef OF
+#define OF(x) x
+#endif
+
 typedef voidpf (ZCALLBACK *open_file_func) OF((voidpf opaque, const char* filename, int mode));
 typedef uLong  (ZCALLBACK *read_file_func) OF((voidpf opaque, voidpf stream, void* buf, uLong size));
 typedef uLong  (ZCALLBACK *write_file_func) OF((voidpf opaque, voidpf stream, const void* buf, uLong size));
