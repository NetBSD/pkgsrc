$NetBSD: patch-pango_pangocoretext.h,v 1.1 2012/03/05 21:02:35 adam Exp $

Use correct CoreText header on Mac OS X.

--- pango/pangocoretext.h.orig	2012-03-05 20:36:03.000000000 +0000
+++ pango/pangocoretext.h
@@ -25,7 +25,7 @@
 
 #include <pango/pango-context.h>
 #include <pango/pango-font.h>
-#include <Carbon/Carbon.h>
+#include <ApplicationServices/ApplicationServices.h>
 
 G_BEGIN_DECLS
 
