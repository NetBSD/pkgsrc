$NetBSD: patch-3rdparty_minizip_ioapi.c,v 1.1 2016/03/02 23:08:22 ryoon Exp $

Fix linking on NetBSD and DragonFly BSD, where fopen, fseek, and ftello
are 64-bit filesize safe.
https://github.com/nmoinvaz/minizip/pull/20

--- 3rdparty/minizip/ioapi.c.orig	2016-01-30 15:39:54.000000000 +0000
+++ 3rdparty/minizip/ioapi.c
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
