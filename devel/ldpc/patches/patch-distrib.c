$NetBSD: patch-distrib.c,v 1.1 2026/03/17 14:25:31 nia Exp $

Fix implicit declaration of sscanf(3), sprintf(3).

--- distrib.c.orig	2026-03-17 14:13:58.706707800 +0000
+++ distrib.c
@@ -13,6 +13,7 @@
  * application.  All use of these programs is entirely at the user's own risk.
  */
 
+#include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 #include <string.h>
