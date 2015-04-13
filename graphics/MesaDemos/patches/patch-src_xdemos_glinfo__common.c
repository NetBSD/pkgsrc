$NetBSD: patch-src_xdemos_glinfo__common.c,v 1.1 2015/04/13 14:00:17 tnn Exp $

--- src/xdemos/glinfo_common.c.orig	2014-07-05 08:17:06.000000000 +0000
+++ src/xdemos/glinfo_common.c
@@ -569,7 +569,7 @@ print_limits(const char *extensions, con
      { 1, GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_EXT, "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS", "GL_EXT_transform_feedback", },
      { 1, GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_EXT, "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS", "GL_EXT_transform_feedback" },
 #endif
-#if defined (GL_ARB_texture_buffer_object)
+#if defined (GL_ARB_texture_buffer_object) && defined(GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT)
       { 1, GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT, "GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT", "GL_ARB_texture_buffer_object" },
       { 1, GL_MAX_TEXTURE_BUFFER_SIZE, "GL_MAX_TEXTURE_BUFFER_SIZE", "GL_ARB_texture_buffer_object" },
 #endif
