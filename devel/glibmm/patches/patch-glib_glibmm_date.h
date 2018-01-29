$NetBSD: patch-glib_glibmm_date.h,v 1.1 2018/01/29 11:45:34 jperkin Exp $

Remove bogus forward declaration.

--- glib/glibmm/date.h.orig	2017-09-17 07:54:16.000000000 +0000
+++ glib/glibmm/date.h
@@ -26,7 +26,6 @@
 #include <ctime>
 
 #ifndef DOXYGEN_SHOULD_SKIP_THIS
-extern "C" { struct tm; }
 #endif
 
 namespace Glib
