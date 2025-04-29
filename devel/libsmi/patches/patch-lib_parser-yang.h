$NetBSD: patch-lib_parser-yang.h,v 1.2 2025/04/29 07:46:55 wiz Exp $

Replace K&R prototype.

--- lib/parser-yang.h.orig	2013-06-04 12:34:00.000000000 +0000
+++ lib/parser-yang.h
@@ -13,7 +13,8 @@
 
 
 
-extern int yangparse();
+struct Parser;
+extern int yangparse(struct Parser *);
 
 
 
