$NetBSD: patch-btparse_src_sym.h,v 1.1 2026/04/29 21:08:25 markd Exp $

Fix ctype(3) usage.

--- ./btparse/src/sym.h.orig	2025-01-29 15:47:18.000000000 +0000
+++ ./btparse/src/sym.h
@@ -6,7 +6,7 @@
 
 /* define some hash function */
 #ifndef HASH_FUN
-#define HASH_FUN(p, h) while ( *p != '\0' ) h = (h<<1) + tolower (*p++);
+#define HASH_FUN(p, h) while ( *p != '\0' ) h = (h<<1) + tolower ((unsigned char)*p++);
 #endif
 
 /* minimum symbol table record */
