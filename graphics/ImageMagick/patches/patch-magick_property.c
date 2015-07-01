$NetBSD: patch-magick_property.c,v 1.4 2015/07/01 12:41:20 wiz Exp $

Adapt for pkgsrc path of lcms2.

--- magick/property.c.orig	2015-06-06 13:46:25.000000000 +0000
+++ magick/property.c
@@ -81,8 +81,8 @@
 #include "magick/version.h"
 #include "magick/xml-tree.h"
 #if defined(MAGICKCORE_LCMS_DELEGATE)
-#if defined(MAGICKCORE_HAVE_LCMS_LCMS2_H)
-#include <lcms/lcms2.h>
+#if defined(MAGICKCORE_HAVE_LCMS2_LCMS2_H)
+#include <lcms2/lcms2.h>
 #elif defined(MAGICKCORE_HAVE_LCMS2_H)
 #include "lcms2.h"
 #elif defined(MAGICKCORE_HAVE_LCMS_LCMS_H)
