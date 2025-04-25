$NetBSD: patch-rsvg-styles.h,v 1.1 2025/04/25 11:44:25 wiz Exp $

Avoid using deprecated header.

--- rsvg-styles.h.orig	2018-10-01 22:50:22.000000000 +0000
+++ rsvg-styles.h
@@ -31,7 +31,7 @@
 #include "rsvg.h"
 #include "rsvg-paint-server.h"
 
-#include <libxml/SAX.h>
+#include <libxml/SAX2.h>
 #include <pango/pango.h>
 
 G_BEGIN_DECLS 
