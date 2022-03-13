$NetBSD: patch-src_mesa_main_extensions.c,v 1.3 2022/03/13 15:50:05 tnn Exp $

atexit() is not a good idea in shared libraries.

FreeBSD reported atexit bug for 10.6:
https://bugs.freedesktop.org/show_bug.cgi?id=91869

--- src/mesa/main/extensions.c.orig	2021-07-14 20:04:58.316035000 +0000
+++ src/mesa/main/extensions.c
@@ -213,7 +213,11 @@ set_extension(struct gl_extensions *ext,
  * This string is allocated early during the first context creation by
  * _mesa_one_time_init_extension_overrides.
  */
+#if defined(HAVE_NOATEXIT)
+static void __attribute__((__destructor__))
+#else
 static void
+#endif
 free_unknown_extensions_strings(void)
 {
    free(unrecognized_extensions.env);
@@ -304,7 +308,9 @@ _mesa_one_time_init_extension_overrides(
       free(env);
    } else {
       unrecognized_extensions.env = env;
+#if !defined(HAVE_NOATEXIT)
       atexit(free_unknown_extensions_strings);
+#endif
    }
 }
 
