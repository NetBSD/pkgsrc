$NetBSD: patch-src_grip.h,v 1.1 2017/08/18 12:21:29 triaxx Exp $

Add a test on the macro needed by pkgsrc cdparanoia.

XXX: this patch could be useless if the cdparanoia package provided by pkgsrc
did not override the default include directory.

--- src/grip.h.orig	2017-06-03 21:05:41.000000000 +0000
+++ src/grip.h
@@ -33,7 +33,7 @@
 #include "status_window.h"
 #include "eggtrayicon.h"
 
-#if defined(HAVE_CDDA_INTERFACE_H) || defined(HAVE_CDDA_CDDA_INTERFACE_H)
+#if defined(HAVE_CDDA_INTERFACE_H) || defined(HAVE_CDDA_CDDA_INTERFACE_H) || defined(HAVE_CDPARANOIA_CDDA_INTERFACE_H)
 #define CDPAR
 #endif
 
