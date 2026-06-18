$NetBSD: patch-XsqlMain.c,v 1.1 2026/06/18 15:45:16 nia Exp $

Fix implicit declaration of exit(3).

--- XsqlMain.c.orig	2026-06-18 15:43:11.399510959 +0000
+++ XsqlMain.c
@@ -17,6 +17,7 @@
 */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include "forms.h"
 
 #include "Xsqldefs.h"
