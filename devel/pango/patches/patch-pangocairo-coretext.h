$NetBSD: patch-pangocairo-coretext.h,v 1.1 2012/05/15 15:07:23 adam Exp $

Let g-ir-scanner skip this header file, since it cannot inspect frameworks.

--- pango/pangocairo-coretext.h.orig	2012-05-15 14:55:59.000000000 +0000
+++ pango/pangocairo-coretext.h
@@ -25,7 +25,9 @@
 
 #include "pangocoretext-private.h"
 #include <pango/pangocairo.h>
+#ifndef __GI_SCANNER__
 #include <cairo-quartz.h>
+#endif
 
 G_BEGIN_DECLS
 
