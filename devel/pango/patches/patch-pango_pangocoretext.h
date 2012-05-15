$NetBSD: patch-pango_pangocoretext.h,v 1.2 2012/05/15 15:07:23 adam Exp $

Use correct CoreText header on Mac OS X.

--- pango/pangocoretext.h.orig	2011-08-16 01:11:08.000000000 +0000
+++ pango/pangocoretext.h
@@ -25,7 +25,9 @@
 
 #include <pango/pango-context.h>
 #include <pango/pango-font.h>
-#include <Carbon/Carbon.h>
+#ifndef __GI_SCANNER__
+#include <ApplicationServices/ApplicationServices.h>
+#endif
 
 G_BEGIN_DECLS
 
