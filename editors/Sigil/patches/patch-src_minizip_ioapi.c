$NetBSD: patch-src_minizip_ioapi.c,v 1.1 2012/11/19 10:57:45 ryoon Exp $

--- src/minizip/ioapi.c.orig	2012-10-27 11:24:40.000000000 +0000
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
