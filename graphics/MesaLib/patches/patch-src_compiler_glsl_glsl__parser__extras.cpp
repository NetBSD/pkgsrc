$NetBSD: patch-src_compiler_glsl_glsl__parser__extras.cpp,v 1.1 2016/04/17 00:03:00 wiz Exp $

atexit() is not a good idea in a library; use destructor attribute.

--- src/compiler/glsl/glsl_parser_extras.cpp.orig	2016-04-04 10:24:28.000000000 +0000
+++ src/compiler/glsl/glsl_parser_extras.cpp
@@ -1938,7 +1938,7 @@ extern "C" {
  * programs would be invalid.  So this should happen at approximately
  * program exit.
  */
-void
+void __attribute__((__destructor__))
 _mesa_destroy_shader_compiler(void)
 {
    _mesa_destroy_shader_compiler_caches();
