$NetBSD: patch-otherlibs_stdune_src_readdir.c,v 1.1 2026/01/11 18:09:04 alnsn Exp $

Extend conditional for HAIKU to SunOS, for no apparent reason.

\todo File upstream.  

--- otherlibs/stdune/src/readdir.c.orig	2026-01-11 01:20:55.502757183 +0000
+++ otherlibs/stdune/src/readdir.c
@@ -18,7 +18,7 @@ typedef struct dirent directory_entry;
 value val_file_type(int typ) {
   switch(typ)
     {
-#ifndef __HAIKU__     
+#if !defined(__HAIKU__) && !defined(__sun)
    case DT_REG:
       return Val_int(0);
     case DT_DIR:
@@ -64,7 +64,7 @@ CAMLprim value caml__dune_filesystem_stu
   v_filename = caml_copy_string(e->d_name);
   v_tuple = caml_alloc_small(2, 0);
   Field(v_tuple, 0) = v_filename;
-#ifndef __HAIKU__
+#if !defined(__HAIKU__) && !defined(__sun)
   Field(v_tuple, 1) = val_file_type(e->d_type);
 #else
   Field(v_tuple, 1) = Val_int(7);
