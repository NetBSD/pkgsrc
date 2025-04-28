$NetBSD: patch-lib_parser-smi.h,v 1.1 2025/04/28 19:34:48 tnn Exp $

Replace K&R prototype.

--- lib/parser-smi.h.orig	2025-04-28 19:31:43.421774384 +0000
+++ lib/parser-smi.h
@@ -24,7 +24,7 @@
 
 
 
-extern int smiparse();
+extern int smiparse(struct Parser *);
 
 
 
