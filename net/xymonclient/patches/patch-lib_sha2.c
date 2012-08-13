$NetBSD: patch-lib_sha2.c,v 1.1 2012/08/13 17:28:25 marino Exp $

--- lib/sha2.c.orig	2011-03-08 17:20:28.000000000 +0000
+++ lib/sha2.c
@@ -51,7 +51,7 @@
 #define SHA384_BLOCK_SIZE  SHA512_BLOCK_SIZE
 #define SHA224_BLOCK_SIZE  SHA256_BLOCK_SIZE
 
-#ifdef HAVE_STDINT_H
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <stdint.h>
 #else
 typedef unsigned char uint8_t;
