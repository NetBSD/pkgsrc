$NetBSD: patch-glib_poppler-structure-element.h,v 1.2 2014/04/30 05:45:03 obache Exp $

* PopplerTextSpan is already defined in poppler.h.
  https://bugs.freedesktop.org/show_bug.cgi?id=78103

--- glib/poppler-structure-element.h.orig	2014-03-11 19:48:54.000000000 +0000
+++ glib/poppler-structure-element.h
@@ -250,9 +250,6 @@ typedef enum {
 } PopplerStructureTableScope;
 
 
-typedef struct _PopplerTextSpan PopplerTextSpan;
-
-
 GType                            poppler_structure_element_get_type               (void) G_GNUC_CONST;
 PopplerStructureElementKind      poppler_structure_element_get_kind               (PopplerStructureElement     *poppler_structure_element);
 gint                             poppler_structure_element_get_page               (PopplerStructureElement     *poppler_structure_element);
