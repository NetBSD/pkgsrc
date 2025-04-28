$NetBSD: patch-lib_parser-yang.h,v 1.1 2025/04/28 19:34:48 tnn Exp $

Replace K&R prototype.

--- lib/parser-yang.h.orig	2025-04-28 19:31:08.092610491 +0000
+++ lib/parser-yang.h
@@ -13,7 +13,7 @@
 
 
 
-extern int yangparse();
+extern int yangparse(struct Parser *);
 
 
 
