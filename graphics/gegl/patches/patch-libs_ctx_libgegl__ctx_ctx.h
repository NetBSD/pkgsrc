$NetBSD: patch-libs_ctx_libgegl__ctx_ctx.h,v 1.1 2026/09/12 21:49:46 wiz Exp $

alloca.h is not portable.
https://gitlab.gnome.org/GNOME/gegl/-/work_items/476

--- libs/ctx/libgegl_ctx/ctx.h.orig	2026-09-12 21:22:57.984061489 +0000
+++ libs/ctx/libgegl_ctx/ctx.h
@@ -51,7 +51,9 @@ extern "C" {
 #include <string.h>
 #ifndef _WIN32
 #include <strings.h>
+#ifndef __NetBSD__
 #include <alloca.h>
+#endif
 #else
 #include <malloc.h>
 #endif
