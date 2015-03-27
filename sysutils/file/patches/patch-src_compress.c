$NetBSD: patch-src_compress.c,v 1.1 2015/03/27 18:57:43 bsiegert Exp $
sig_t is not defined by default on SunOS

--- src/compress.c.orig	2014-12-16 16:07:12.000000000 +0000
+++ src/compress.c
@@ -59,6 +59,9 @@ FILE_RCSID("@(#)$File: compress.c,v 1.77
 #define BUILTIN_DECOMPRESS
 #include <zlib.h>
 #endif
+#ifdef __sun
+typedef void (*sig_t)(int);
+#endif
 
 private const struct {
 	const char magic[8];
