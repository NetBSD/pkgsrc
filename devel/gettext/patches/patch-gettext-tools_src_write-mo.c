$NetBSD: patch-gettext-tools_src_write-mo.c,v 1.1 2020/08/12 23:31:09 joerg Exp $

Workaround for /dev/null failing with O_TRUNC|O_WRONLY in Illumos zones.

--- gettext-tools/src/write-mo.c.orig	2020-07-05 22:39:41.000000000 +0000
+++ gettext-tools/src/write-mo.c
@@ -809,6 +809,9 @@ msgdomain_write_mo (message_list_ty *mlp
              (through SIGSEGV or SIGBUS).  */
           struct supersede_final_action action;
           FILE *output_file =
+#ifdef __sun__
+            strcmp(file_name, "/dev/null") == 0 ? fopen (file_name, "wb") :
+#endif
             fopen_supersede (file_name, "wb", true, true, &action);
           if (output_file == NULL)
             {
