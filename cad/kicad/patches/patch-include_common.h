$NetBSD: patch-include_common.h,v 1.1.1.1 2014/02/17 20:38:59 bouyer Exp $

Remove bogus error

--- include/common.h.orig	2014-02-14 23:04:25.000000000 +0100
+++ include/common.h	2014-02-14 23:04:40.000000000 +0100
@@ -46,13 +46,6 @@
 #   error "You must use '--enable-printarch' in your wx library configuration."
 #endif
 
-#if defined( __WXGTK__ )
-#   if !wxUSE_LIBGNOMEPRINT && !wxUSE_GTKPRINT && !SWIG
-#       error "You must use '--with-gnomeprint' or '--with-gtkprint' in your wx library configuration."
-#   endif
-#endif
-
-
 class wxAboutDialogInfo;
 
 // Flag for special keys
