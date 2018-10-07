$NetBSD: patch-src_compiler_builtin__type__macros.h,v 1.1 2018/10/07 23:49:31 ryoon Exp $

Workaround netbsd headers.

--- src/compiler/builtin_type_macros.h.orig	2018-09-07 21:18:07.000000000 +0000
+++ src/compiler/builtin_type_macros.h
@@ -28,6 +28,18 @@
  * language version or extension might provide them.
  */
 
+#ifdef __NetBSD__ /* XXX https://mail-index.netbsd.org/tech-userlevel/2018/09/08/msg011381.html */
+#undef uint8_t
+#undef uint16_t
+#undef uint32_t
+#undef uint64_t
+#undef int8_t
+#undef int16_t
+#undef int32_t
+#undef int64_t
+#endif
+
+
 DECL_TYPE(error,  GL_INVALID_ENUM, GLSL_TYPE_ERROR, 0, 0)
 DECL_TYPE(void,   GL_INVALID_ENUM, GLSL_TYPE_VOID,  0, 0)
 
