$NetBSD: patch-src_glsl_glsl__parser__extras.cpp,v 1.1 2016/01/27 07:39:54 wiz Exp $

atexit() is not a good idea in shared libraries.

--- src/glsl/glsl_parser_extras.cpp.orig	2016-01-07 16:17:53.000000000 +0000
+++ src/glsl/glsl_parser_extras.cpp
@@ -1967,7 +1967,7 @@ extern "C" {
  * programs would be invalid.  So this should happen at approximately
  * program exit.
  */
-void
+void __attribute__((__destructor__))
 _mesa_destroy_shader_compiler(void)
 {
    _mesa_destroy_shader_compiler_caches();
