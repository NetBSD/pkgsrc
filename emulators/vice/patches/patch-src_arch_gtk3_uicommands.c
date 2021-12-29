$NetBSD: patch-src_arch_gtk3_uicommands.c,v 1.1 2021/12/29 14:31:24 rhialto Exp $

We disable generating the PDF docs (because of expensive dependencies),
so instead, try to show the cheaply generated html version.

--- src/arch/gtk3/uicommands.c.orig	2021-12-24 19:27:40.000000000 +0000
+++ src/arch/gtk3/uicommands.c
@@ -372,7 +372,7 @@ gboolean ui_open_manual_callback(GtkWidg
     path = archdep_get_vice_docsdir();
 
     /* first try opening the pdf */
-    uri = archdep_join_paths(path, "vice.pdf", NULL);
+    uri = archdep_join_paths(path, "html/vice_toc.html", NULL);
     debug_gtk3("URI before GTK3: %s", uri);
     final_uri = g_filename_to_uri(uri, NULL, &error);
     debug_gtk3("final URI (pdf): %s", final_uri);
