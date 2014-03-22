$NetBSD: patch-xftglyphs.c,v 1.1 2014/03/22 21:44:53 spz Exp $

make it deal gracefully with both freetype 2.4.* and 2.5.*

--- xftglyphs.c.orig	2005-03-02 05:32:14.000000000 +0000
+++ xftglyphs.c
@@ -23,7 +23,8 @@
  */
 
 #include "xftint.h"
-#include <freetype/ftoutln.h>
+#include <ft2build.h>
+#include FT_OUTLINE_H
 
 static const int    filters[3][3] = {
     /* red */
