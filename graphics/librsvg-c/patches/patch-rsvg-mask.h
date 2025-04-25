$NetBSD: patch-rsvg-mask.h,v 1.1 2025/04/25 11:44:25 wiz Exp $

Avoid using deprecated header.

--- rsvg-mask.h.orig	2018-10-01 22:50:22.000000000 +0000
+++ rsvg-mask.h
@@ -31,7 +31,7 @@
 #include "rsvg-css.h"
 #include "rsvg-styles.h"
 #include "rsvg-shapes.h"
-#include <libxml/SAX.h>
+#include <libxml/SAX2.h>
 
 G_BEGIN_DECLS 
 
