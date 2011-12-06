$NetBSD: patch-Fl__Print__Dialog2.cxx,v 1.1 2011/12/06 19:54:46 joerg Exp $

--- Fl_Print_Dialog2.cxx.orig	2011-12-06 15:56:14.000000000 +0000
+++ Fl_Print_Dialog2.cxx
@@ -52,6 +52,7 @@
 
 #ifdef HAVE_LIBCUPS
 #  include <cups/cups.h>
+#  include <cups/ppd.h>
 #endif // HAVE_LIBCUPS
 
 
