$NetBSD: patch-gst_gsttaglist.c,v 1.1 2013/12/17 11:39:38 jperkin Exp $

g-ir-scanner on Darwin doesn't like empty comments.

--- gst/gsttaglist.c.orig	2013-07-04 23:50:56.000000000 +0000
+++ gst/gsttaglist.c
@@ -1522,7 +1522,7 @@ gst_tag_list_get_ ## name ## _index (con
   return ret;                                                           \
 }
 
-#define COPY_FUNC /**/
+#define COPY_FUNC /* */
 /**
  * gst_tag_list_get_boolean:
  * @list: a #GstTagList to get the tag from
