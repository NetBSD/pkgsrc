$NetBSD: patch-cogl_cogl-attribute-buffer.c,v 1.1 2014/01/03 12:32:24 obache Exp $

* remove spurious COGL_GTYPE_DEFINE_CLASS reference
  https://git.gnome.org/browse/cogl/commit/?h=cogl-1.16&id=3b14acdbcc39a43cdeac65fd9e49775f887fe5ef

--- cogl/cogl-attribute-buffer.c.orig	2013-09-23 14:02:31.000000000 +0000
+++ cogl/cogl-attribute-buffer.c
@@ -37,7 +37,6 @@
 static void _cogl_attribute_buffer_free (CoglAttributeBuffer *array);
 
 COGL_BUFFER_DEFINE (AttributeBuffer, attribute_buffer);
-COGL_GTYPE_DEFINE_CLASS (AttributeBuffer, attribute_buffer);
 
 CoglAttributeBuffer *
 cogl_attribute_buffer_new_with_size (CoglContext *context,
