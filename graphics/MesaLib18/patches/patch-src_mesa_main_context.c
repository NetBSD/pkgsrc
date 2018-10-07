$NetBSD: patch-src_mesa_main_context.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

* Fix exit time segfault of qt5 application with modular xorg

Bug 82246 (atexit) - Libraries should not call atexit()

https://bugs.freedesktop.org/show_bug.cgi?id=82246

FreeBSD reported atexit bug for 10.6:
https://bugs.freedesktop.org/show_bug.cgi?id=91869

--- src/mesa/main/context.c.orig	2017-11-20 14:25:47.000000000 +0000
+++ src/mesa/main/context.c
@@ -354,11 +354,23 @@ mtx_t OneTimeLock = _MTX_INITIALIZER_NP;
  * Calls all the various one-time-fini functions in Mesa
  */
 
+#if defined(HAVE_NOATEXIT)
+static GLbitfield api_init_mask = 0x0;
+static void __attribute__((__destructor__))
+#else
 static void
+#endif
 one_time_fini(void)
 {
+#if defined(HAVE_NOATEXIT)
+   if (api_init_mask) {
+      _mesa_destroy_shader_compiler();
+      _mesa_locale_fini();
+   }
+#else
    _mesa_destroy_shader_compiler();
    _mesa_locale_fini();
+#endif
 }
 
 /**
@@ -373,7 +385,9 @@ one_time_fini(void)
 static void
 one_time_init( struct gl_context *ctx )
 {
+#if !defined(HAVE_NOATEXIT)
    static GLbitfield api_init_mask = 0x0;
+#endif
 
    mtx_lock(&OneTimeLock);
 
@@ -398,7 +412,9 @@ one_time_init( struct gl_context *ctx )
          _mesa_ubyte_to_float_color_tab[i] = (float) i / 255.0F;
       }
 
+#if !defined(HAVE_NOATEXIT)
       atexit(one_time_fini);
+#endif
 
 #if defined(DEBUG)
       if (MESA_VERBOSE != 0) {
