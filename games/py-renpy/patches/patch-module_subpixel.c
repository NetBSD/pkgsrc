$NetBSD: patch-module_subpixel.c,v 1.1 2017/06/24 19:39:47 adam Exp $

Fix for duplicate symbol PyGAME_C_API.

--- module/subpixel.c.orig	2017-06-24 17:57:56.000000000 +0000
+++ module/subpixel.c
@@ -7,7 +7,7 @@
  */
 
 #include "renpy.h"
-#include <pygame/pygame.h>
+#include <pygame/_pygame.h>
 #include <stdio.h>
 #include <math.h>
 
