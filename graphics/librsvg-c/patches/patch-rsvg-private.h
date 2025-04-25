$NetBSD: patch-rsvg-private.h,v 1.1 2025/04/25 11:44:25 wiz Exp $

Avoid using deprecated header.

--- rsvg-private.h.orig	2025-04-25 11:42:58.711160861 +0000
+++ rsvg-private.h
@@ -31,7 +31,7 @@
 
 #include "rsvg.h"
 
-#include <libxml/SAX.h>
+#include <libxml/SAX2.h>
 #include <libxml/xmlmemory.h>
 #include <pango/pango.h>
 #include <glib.h>
