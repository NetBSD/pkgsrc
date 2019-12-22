$NetBSD: patch-libcurvecpr_lib_bytes.c,v 1.1 2019/12/22 22:28:54 joerg Exp $

--- libcurvecpr/lib/bytes.c.orig	2019-12-22 17:53:50.601852676 +0000
+++ libcurvecpr/lib/bytes.c
@@ -4,10 +4,6 @@
 
 #include <string.h>
 
-#include <sodium/crypto_uint16.h>
-#include <sodium/crypto_uint32.h>
-#include <sodium/crypto_uint64.h>
-
 void curvecpr_bytes_copy (void *destination, const void *source, size_t num)
 {
     char *destination_copier = destination;
