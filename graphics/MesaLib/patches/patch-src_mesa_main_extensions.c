$NetBSD: patch-src_mesa_main_extensions.c,v 1.1 2016/01/27 07:39:54 wiz Exp $

atexit() is not a good idea in shared libraries.

--- src/mesa/main/extensions.c.orig	2016-01-07 16:17:53.000000000 +0000
+++ src/mesa/main/extensions.c
@@ -256,7 +256,7 @@ get_extension_override( struct gl_contex
  * These strings are allocated early during the first context creation by
  * _mesa_one_time_init_extension_overrides.
  */
-static void
+static void __attribute__((__destructor__))
 free_unknown_extensions_strings(void)
 {
    free(extra_extensions);
@@ -277,7 +277,7 @@ _mesa_one_time_init_extension_overrides(
    int len;
    size_t offset;
 
-   atexit(free_unknown_extensions_strings);
+   /* atexit(free_unknown_extensions_strings); */
 
    memset(&_mesa_extension_override_enables, 0, sizeof(struct gl_extensions));
    memset(&_mesa_extension_override_disables, 0, sizeof(struct gl_extensions));
