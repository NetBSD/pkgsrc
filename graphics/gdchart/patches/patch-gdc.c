$NetBSD: patch-gdc.c,v 1.1 2026/06/14 15:56:38 nia Exp $

Fix implicit declaration of strlen(3).

--- gdc.c.orig	2004-12-17 18:11:54.000000000 +0000
+++ gdc.c
@@ -4,6 +4,7 @@
 #define GDC_INCL
 #define GDC_LIB
 #include <math.h>
+#include <string.h>
 #include "gdc.h"
 
 struct	GDC_FONT_T	GDC_fontc[GDC_numfonts] = { (gdFontPtr)NULL, 8,  5,
