$NetBSD: patch-print.c,v 1.1 2026/03/18 15:14:35 nia Exp $

Fix implicit function declarations.

--- print.c.orig	2026-03-18 14:43:02.275295827 +0000
+++ print.c
@@ -19,6 +19,7 @@
 #include <sys/stat.h>
 #include <ctype.h>
 #include <stdio.h>
+#include <strings.h>
 #include <math.h>
 
 #include <X11/IntrinsicP.h>
