$NetBSD: patch-plugins_document-manager_anjuta-bookmarks.c,v 1.1 2025/10/17 07:25:26 kikadf Exp $

* Fix CVE-2021-42522, https://gitlab.gnome.org/Archive/anjuta/-/issues/12

--- plugins/document-manager/anjuta-bookmarks.c.orig	2025-10-17 07:10:40.044952045 +0000
+++ plugins/document-manager/anjuta-bookmarks.c
@@ -866,6 +866,7 @@ read_bookmarks (AnjutaBookmarks* bookmar
 			anjuta_bookmarks_add_file (bookmarks, file, line, title);
 			g_free(uri);
 			g_free (title);
+			g_free(line_text);
 		}
 	}
 }
