$NetBSD: patch-src_mesa_main_context.c,v 1.3 2015/09/26 08:45:02 tnn Exp $

* Fix exit time segfault of qt5 application with modular xorg

--- src/mesa/main/context.c.orig	2015-09-11 17:41:47.000000000 +0000
+++ src/mesa/main/context.c
@@ -350,11 +350,14 @@ mtx_t OneTimeLock = _MTX_INITIALIZER_NP;
  * Calls all the various one-time-fini functions in Mesa
  */
 
-static void
+static GLbitfield api_init_mask = 0x0;
+static void __attribute__((__destructor__))
 one_time_fini(void)
 {
-   _mesa_destroy_shader_compiler();
-   _mesa_locale_fini();
+   if (api_init_mask) {
+      _mesa_destroy_shader_compiler();
+      _mesa_locale_fini();
+   }
 }
 
 /**
@@ -369,7 +372,6 @@ one_time_fini(void)
 static void
 one_time_init( struct gl_context *ctx )
 {
-   static GLbitfield api_init_mask = 0x0;
 
    mtx_lock(&OneTimeLock);
 
@@ -394,8 +396,6 @@ one_time_init( struct gl_context *ctx )
          _mesa_ubyte_to_float_color_tab[i] = (float) i / 255.0F;
       }
 
-      atexit(one_time_fini);
-
 #if defined(DEBUG) && defined(__DATE__) && defined(__TIME__)
       if (MESA_VERBOSE != 0) {
 	 _mesa_debug(ctx, "Mesa %s DEBUG build %s %s\n",
