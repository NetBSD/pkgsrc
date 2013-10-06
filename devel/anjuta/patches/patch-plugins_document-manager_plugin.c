$NetBSD: patch-plugins_document-manager_plugin.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/document-manager/plugin.c.orig	2013-09-02 06:53:35.000000000 +0000
+++ plugins/document-manager/plugin.c
@@ -931,7 +931,7 @@ update_status (DocmanPlugin *plugin, IAn
 
 		anjuta_status_set_default (status, _("Line"), "%04d", line);
 		anjuta_status_set_default (status, _("Col"), "%03d", col);
-		anjuta_status_set_default (status, _("Mode"), edit);
+		anjuta_status_set_default (status, _("Mode"), "%s", edit);
 		// anjuta_status_set_default (status, _("EOL"), mode);
 
 		g_free (edit);
