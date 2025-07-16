$NetBSD: patch-src_sha256.c,v 1.1 2025/07/16 09:27:17 jperkin Exp $

Fix includes.

--- src/sha256.c.orig	2025-07-16 09:18:45.169722613 +0000
+++ src/sha256.c
@@ -12,6 +12,7 @@
 
 /*************************** HEADER FILES ***************************/
 #include <stddef.h>
+#include <string.h>
 
 /****************************** MACROS ******************************/
 #define SHA256_BLOCK_SIZE 32            // SHA256 outputs a 32 byte digest
