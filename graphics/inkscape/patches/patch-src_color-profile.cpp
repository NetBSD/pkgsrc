$NetBSD: patch-src_color-profile.cpp,v 1.1 2012/11/16 00:54:04 joerg Exp $

--- src/color-profile.cpp.orig	2012-11-15 16:10:51.000000000 +0000
+++ src/color-profile.cpp
@@ -103,6 +103,8 @@ extern guint update_in_progress;
 
 static SPObjectClass *cprof_parent_class;
 
+namespace Inkscape {
+
 class ColorProfileImpl {
 public:
 #if defined(HAVE_LIBLCMS1) || defined(HAVE_LIBLCMS2)
@@ -129,6 +131,7 @@ public:
 #endif // defined(HAVE_LIBLCMS1) || defined(HAVE_LIBLCMS2)
 };
 
+}
 
 
 namespace Inkscape {
