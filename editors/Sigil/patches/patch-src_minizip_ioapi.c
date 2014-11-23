$NetBSD: patch-src_minizip_ioapi.c,v 1.2 2014/11/23 19:27:29 wiz Exp $

Fix linking on NetBSD and DragonFly BSD, where fopen, fseek, and ftello
are 64-bit filesize safe.

--- src/minizip/ioapi.c.orig	2014-10-12 14:45:14.000000000 +0000
+++ src/minizip/ioapi.c
@@ -14,6 +14,12 @@
         #define _CRT_SECURE_NO_WARNINGS
 #endif
 
+#if defined(__NetBSD__) || defined(__DragonFly__)
+#define fopen64 fopen
+#define fseeko64 fseek
+#define ftello64 ftello
+#endif
+
 #include "ioapi.h"
 
 voidpf call_zopen64 (const zlib_filefunc64_32_def* pfilefunc,const void*filename,int mode)
