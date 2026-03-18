$NetBSD: patch-brushOp.c,v 1.1 2026/03/18 15:14:35 nia Exp $

Fix implicit function declarations.

--- brushOp.c.orig	2026-03-18 14:42:35.525192591 +0000
+++ brushOp.c
@@ -17,4 +17,5 @@
 
 #include <stdlib.h>
+#include <strings.h>
 #include <math.h>
 
