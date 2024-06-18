$NetBSD: patch-rect.c,v 1.1 2024/06/18 08:44:33 markd Exp $

c99 fixes from Fedora 

--- rect.c.orig	2011-05-16 16:21:59.000000000 +0000
+++ rect.c
@@ -50,7 +50,7 @@
 
 void DumpRectPath(FP, LtX, LtY, RbX, RbY, Indent, LastLF)
    FILE *FP;
-   int LtX, LtY, RbX, RbY, Indent;
+   int LtX, LtY, RbX, RbY, Indent, LastLF;
 {
    register int i;
 
