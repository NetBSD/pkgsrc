$NetBSD: patch-libs_ctx_libgegl__ctx_ctx.h,v 1.2 2026/09/27 13:14:03 nia Exp $

alloca.h is not portable.
https://gitlab.gnome.org/GNOME/gegl/-/work_items/476

--- libs/ctx/libgegl_ctx/ctx.h.orig	2026-09-07 02:51:56.000000000 +0000
+++ libs/ctx/libgegl_ctx/ctx.h
@@ -51,7 +51,9 @@ extern "C" {
 #include <string.h>
 #ifndef _WIN32
 #include <strings.h>
+#if defined(__linux__) || defined(__sun)
 #include <alloca.h>
+#endif
 #else
 #include <malloc.h>
 #endif
