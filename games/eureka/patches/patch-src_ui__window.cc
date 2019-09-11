$NetBSD: patch-src_ui__window.cc,v 1.1 2019/09/11 16:26:17 micha Exp $

Prepare for FLTK 1.4 and allow minor numbers larger than 3 too.

--- src/ui_window.cc.orig	2018-07-22 10:30:09.000000000 +0000
+++ src/ui_window.cc
@@ -30,8 +30,9 @@
 #include <unistd.h>
 #endif
 
+/* pkgsrc: Prepare for the upcoming FLTK 1.4.0 release */
 #if (FL_MAJOR_VERSION != 1 ||  \
-     FL_MINOR_VERSION != 3 ||  \
+     FL_MINOR_VERSION < 3 ||  \
      FL_PATCH_VERSION < 0)
 #error "Require FLTK version 1.3.0 or later"
 #endif
