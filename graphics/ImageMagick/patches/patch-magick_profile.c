$NetBSD: patch-magick_profile.c,v 1.3 2015/07/01 12:41:20 wiz Exp $

Adapt for pkgsrc path of lcms2.

--- magick/profile.c.orig	2015-06-06 13:46:25.000000000 +0000
+++ magick/profile.c
@@ -65,9 +65,9 @@
 #include "magick/token.h"
 #include "magick/utility.h"
 #if defined(MAGICKCORE_LCMS_DELEGATE)
-#if defined(MAGICKCORE_HAVE_LCMS_LCMS2_H)
+#if defined(MAGICKCORE_HAVE_LCMS2_LCMS2_H)
 #include <wchar.h>
-#include <lcms/lcms2.h>
+#include <lcms2/lcms2.h>
 #elif defined(MAGICKCORE_HAVE_LCMS2_H)
 #include <wchar.h>
 #include "lcms2.h"
