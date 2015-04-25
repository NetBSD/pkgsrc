$NetBSD: patch-src_mesa_main_context.c,v 1.2 2015/04/25 11:19:18 tnn Exp $

* Fix exit time segfault of qt5 application with modular xorg

--- src/mesa/main/context.c.orig	2015-03-28 18:20:39.000000000 +0000
+++ src/mesa/main/context.c
@@ -378,10 +378,10 @@ mtx_t OneTimeLock = _MTX_INITIALIZER_NP;
  *
  * \sa _math_init().
  */
+static GLbitfield api_init_mask = 0x0;
 static void
 one_time_init( struct gl_context *ctx )
 {
-   static GLbitfield api_init_mask = 0x0;
 
    mtx_lock(&OneTimeLock);
 
@@ -428,14 +428,16 @@ one_time_init( struct gl_context *ctx )
 
    mtx_unlock(&OneTimeLock);
 
-   /* Hopefully atexit() is widely available.  If not, we may need some
-    * #ifdef tests here.
-    */
-   atexit(_mesa_destroy_shader_compiler);
-
    dummy_enum_func();
 }
 
+static void __attribute__((__destructor__))
+one_time_fini(void)
+{
+  if (api_init_mask)
+    _mesa_destroy_shader_compiler();
+}
+
 
 /**
  * Initialize fields of gl_current_attrib (aka ctx->Current.*)
