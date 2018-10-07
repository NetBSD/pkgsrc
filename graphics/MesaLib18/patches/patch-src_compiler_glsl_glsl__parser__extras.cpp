$NetBSD: patch-src_compiler_glsl_glsl__parser__extras.cpp,v 1.1 2018/10/07 23:49:31 ryoon Exp $

atexit() is not a good idea in a library; use destructor attribute.

--- src/compiler/glsl/glsl_parser_extras.cpp.orig	2017-09-25 16:56:18.000000000 +0000
+++ src/compiler/glsl/glsl_parser_extras.cpp
@@ -2224,7 +2224,11 @@ extern "C" {
  * programs would be invalid.  So this should happen at approximately
  * program exit.
  */
+#if defined(HAVE_NOATEXIT)
+void __attribute__((__destructor__))
+#else
 void
+#endif
 _mesa_destroy_shader_compiler(void)
 {
    _mesa_destroy_shader_compiler_caches();
