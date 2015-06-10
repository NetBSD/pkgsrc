$NetBSD: patch-pango_pangocoretext.h,v 1.3 2015/06/10 23:30:24 prlw1 Exp $

Use correct CoreText header on Mac OS X.

--- pango/pangocoretext.h.orig	2015-05-27 17:38:43.000000000 +0000
+++ pango/pangocoretext.h
@@ -24,7 +24,9 @@
 #define __PANGOCORETEXT_H__
 
 #include <pango/pango.h>
-#include <Carbon/Carbon.h>
+#ifndef __GI_SCANNER__
+#include <ApplicationServices/ApplicationServices.h>
+#endif
 
 G_BEGIN_DECLS
 
