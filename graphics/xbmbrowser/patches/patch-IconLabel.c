$NetBSD: patch-IconLabel.c,v 1.1 2026/03/18 14:47:39 nia Exp $

Fix implicit function declarations.

--- IconLabel.c.orig	2026-03-18 14:22:18.963678185 +0000
+++ IconLabel.c
@@ -33,6 +33,7 @@
 
 #include <X11/IntrinsicP.h>
 #include <X11/StringDefs.h>
+#include <X11/Xmu/Drawing.h>
 #include "IconLabelP.h"          /* Private header file */
 
 /* shape extension stuff */
