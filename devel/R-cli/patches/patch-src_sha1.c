$NetBSD: patch-src_sha1.c,v 1.1 2025/07/16 09:27:17 jperkin Exp $

Fix includes.

--- src/sha1.c.orig	2025-07-16 09:18:18.652026675 +0000
+++ src/sha1.c
@@ -11,6 +11,7 @@
 
 /*************************** HEADER FILES ***************************/
 #include <stddef.h>
+#include <string.h>
 
 /****************************** MACROS ******************************/
 #define SHA1_BLOCK_SIZE 20              // SHA1 outputs a 20 byte digest
