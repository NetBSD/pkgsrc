$NetBSD: patch-gtk3_utils.h,v 1.1 2021/04/25 18:24:43 nia Exp $

Include missing header for std::free. Fixes building with gcc10.

--- gtk3/utils.h.orig	2021-01-25 21:23:36.273540700 +0000
+++ gtk3/utils.h
@@ -9,6 +9,7 @@
 
 #include <cairo.h>
 #include <glib-object.h>
+#include <cstdlib>
 #include <memory>
 #include <utility>
 
