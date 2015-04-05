$NetBSD: patch-src_mesa_main_context.c,v 1.1 2015/04/05 17:01:37 tnn Exp $

* Fix exit time segfault of qt5 application with modular xorg

--- src/mesa/main/context.c.orig	2011-10-15 00:43:58.000000000 +0000
+++ src/mesa/main/context.c
@@ -383,10 +383,10 @@ _glthread_DECLARE_STATIC_MUTEX(OneTimeLo
  *
  * \sa _math_init().
  */
+static GLbitfield api_init_mask = 0x0;
 static void
 one_time_init( struct gl_context *ctx )
 {
-   static GLbitfield api_init_mask = 0x0;
 
    _glthread_LOCK_MUTEX(OneTimeLock);
 
@@ -441,14 +441,16 @@ one_time_init( struct gl_context *ctx )
 
    _glthread_UNLOCK_MUTEX(OneTimeLock);
 
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
