$NetBSD: patch-clutter_clutter-script.c,v 1.1 2013/05/30 15:35:46 joerg Exp $

--- clutter/clutter-script.c.orig	2013-05-29 19:56:00.000000000 +0000
+++ clutter/clutter-script.c
@@ -183,7 +183,7 @@
 #include "clutter-private.h"
 #include "clutter-debug.h"
 
-#include "json/json-parser.h"
+#include <json-glib/json-glib.h>
 
 enum
 {
