$NetBSD: patch-gtk3_utils.h,v 1.2 2024/02/10 12:01:44 ryoon Exp $

Include missing header for std::free. Fixes building with gcc10.

--- gtk3/utils.h.orig	2023-11-25 14:07:34.909973541 +0000
+++ gtk3/utils.h
@@ -12,6 +12,7 @@
 #include <glib-object.h>
 #include <memory>
 #include <utility>
+#include <cstdlib>
 
 namespace fcitx::gtk {
 
