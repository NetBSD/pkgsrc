$NetBSD: patch-src_mesa_main_context.c,v 1.6 2022/03/13 15:52:50 tnn Exp $

atexit() is not a good idea in shared libraries.

--- src/mesa/main/context.c.orig	2021-07-14 20:04:58.296035000 +0000
+++ src/mesa/main/context.c
@@ -324,7 +324,11 @@ _mesa_destroy_visual( struct gl_config *
  * Calls all the various one-time-fini functions in Mesa
  */
 
+#if defined(HAVE_NOATEXIT)
+static void __attribute__((__destructor__))
+#else
 static void
+#endif
 one_time_fini(void)
 {
    glsl_type_singleton_decref();
@@ -357,7 +361,9 @@ one_time_init(void)
       _mesa_ubyte_to_float_color_tab[i] = (float) i / 255.0F;
    }
 
+#if !defined(HAVE_NOATEXIT)
    atexit(one_time_fini);
+#endif
 
 #if defined(DEBUG)
    if (MESA_VERBOSE != 0) {
