$NetBSD: patch-tmesh_tmesh-cmds.c,v 1.1 2013/02/26 23:39:18 joerg Exp $

--- tmesh/tmesh-cmds.c.orig	2013-02-26 21:55:25.000000000 +0000
+++ tmesh/tmesh-cmds.c
@@ -238,7 +238,7 @@ _tmesh_ls_output_argv(char **_output, st
   args += skip;
   for (; argc-- > 0; ) {
     tme_output_append(_output, " ");
-    tme_output_append(_output, *(args++));
+    tme_output_append(_output, "%s", *(args++));
   }
 }
 
@@ -524,7 +524,7 @@ _tmesh_command_connect(struct tmesh *tme
 
     /* this must be an element: */
     if (entry->tmesh_fs_dirent_type != TMESH_FS_DIRENT_ELEMENT) {
-      tme_output_append(_output, element1_args[0]);
+      tme_output_append(_output, "%s", element1_args[0]);
       return (ENOTSOCK);
     }
     element1 = entry->tmesh_fs_dirent_value;
@@ -546,7 +546,7 @@ _tmesh_command_connect(struct tmesh *tme
 
     /* it must be an element: */
     if (entry->tmesh_fs_dirent_type != TMESH_FS_DIRENT_ELEMENT) {
-      tme_output_append(_output, value->tmesh_parser_value_pathname0);
+      tme_output_append(_output, "%s", value->tmesh_parser_value_pathname0);
       return (ENOTSOCK);
     }
     element0 = entry->tmesh_fs_dirent_value;
