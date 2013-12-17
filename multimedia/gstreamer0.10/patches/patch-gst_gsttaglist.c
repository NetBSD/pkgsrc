$NetBSD: patch-gst_gsttaglist.c,v 1.1 2013/12/17 11:35:20 jperkin Exp $

g-ir-scanner on Darwin doesn't like empty comments.

--- gst/gsttaglist.c.orig	2011-12-30 01:14:35.000000000 +0000
+++ gst/gsttaglist.c
@@ -1406,7 +1406,7 @@ gst_tag_list_get_ ## name ## _index (con
  * _get_ulong*() and _get_pointer*()? - they are not really useful/common
  * enough to warrant convenience accessor functions */
 
-#define COPY_FUNC /**/
+#define COPY_FUNC /* */
 /**
  * gst_tag_list_get_char:
  * @list: a #GstTagList to get the tag from
