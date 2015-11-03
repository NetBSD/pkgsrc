$NetBSD: patch-gcc_config_darwin.c,v 1.1 2015/11/03 13:59:10 jperkin Exp $

Backport fix for https://gcc.gnu.org/bugzilla/show_bug.cgi?id=66523

--- gcc/config/darwin.c.orig	2014-04-07 06:40:18.000000000 +0000
+++ gcc/config/darwin.c
@@ -1204,6 +1204,9 @@ darwin_encode_section_info (tree decl, r
 void
 darwin_mark_decl_preserved (const char *name)
 {
+  if (darwin_label_is_anonymous_local_objc_name (name))
+    return;
+
   fprintf (asm_out_file, "\t.no_dead_strip ");
   assemble_name (asm_out_file, name);
   fputc ('\n', asm_out_file);
