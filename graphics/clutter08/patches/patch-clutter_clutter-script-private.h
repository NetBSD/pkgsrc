$NetBSD: patch-clutter_clutter-script-private.h,v 1.1 2013/05/30 15:35:46 joerg Exp $

--- clutter/clutter-script-private.h.orig	2013-05-29 19:54:53.000000000 +0000
+++ clutter/clutter-script-private.h
@@ -27,7 +27,7 @@
 #define __CLUTTER_SCRIPT_PRIVATE_H__
 
 #include <glib-object.h>
-#include "json/json-types.h"
+#include <json-glib/json-glib.h>
 #include "clutter-color.h"
 #include "clutter-types.h"
 #include "clutter-script.h"
