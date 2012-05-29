$NetBSD: patch-src_gpk-application.c,v 1.1 2012/05/29 12:18:57 obache Exp $

* glib2>=2.30 deprecate g_format_size_for_display, add g_format_size.

--- src/gpk-application.c.orig	2008-12-09 08:22:40.000000000 +0000
+++ src/gpk-application.c
@@ -1035,7 +1035,7 @@ gpk_application_details_cb (PkClient *cl
 	/* if non-zero, set the size */
 	if (details->size > 0) {
 		/* set the size */
-		value = g_format_size_for_display (details->size);
+		value = g_format_size (details->size);
 		if (egg_strequal (details->id->data, "meta"))
 			/* TRANSLATORS: the size of the meta package */
 			gpk_application_add_detail_item (application, _("Size"), value, NULL);
