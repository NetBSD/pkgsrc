$NetBSD: patch-otherlibs_stdune__filesystem__stubs_readdir.c,v 1.1 2023/11/05 21:26:42 jaapb Exp $

--- otherlibs/stdune/dune_filesystem_stubs/readdir.c.orig	2023-10-09 11:08:29.000000000 +0000
+++ otherlibs/stdune/dune_filesystem_stubs/readdir.c
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
