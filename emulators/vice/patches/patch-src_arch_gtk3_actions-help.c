$NetBSD: patch-src_arch_gtk3_actions-help.c,v 1.1 2022/12/31 18:30:00 rhialto Exp $

We disable generating the PDF docs (because of expensive dependencies),
so instead, try to show the cheaply generated html version.

--- src/arch/gtk3/actions-help.c.orig	2022-12-30 19:22:07.891133431 +0000
+++ src/arch/gtk3/actions-help.c
@@ -63,7 +63,7 @@ static void help_manual_action(void)
      */
     path = archdep_get_vice_docsdir();
 
-    uri = util_join_paths(path, "vice.pdf", NULL);
+    uri = util_join_paths(path, "html/vice_toc.html", NULL);
     debug_gtk3("URI before GTK3: %s", uri);
     final_uri = g_filename_to_uri(uri, NULL, &error);
     debug_gtk3("final URI (pdf): %s", final_uri);
