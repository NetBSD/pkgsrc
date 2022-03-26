$NetBSD: patch-src_dune__filesystem__stubs_readdir.c,v 1.1 2022/03/26 23:19:32 tnn Exp $

no DT_REG on SunOS

--- src/dune_filesystem_stubs/readdir.c.orig	2022-01-26 15:17:00.000000000 +0000
+++ src/dune_filesystem_stubs/readdir.c
@@ -18,7 +18,7 @@ typedef struct dirent directory_entry;
 value val_file_type(int typ) {
   switch(typ)
     {
-#ifndef __HAIKU__     
+#if !defined(__HAIKU__) && !defined(__sun)
    case DT_REG:
       return Val_int(0);
     case DT_DIR:
@@ -59,7 +59,7 @@ CAMLprim value caml__dune_filesystem_stu
   v_filename = caml_copy_string(e->d_name);
   v_tuple = caml_alloc_small(2, 0);
   Field(v_tuple, 0) = v_filename;
-#ifndef __HAIKU__
+#if !defined(__HAIKU__) && !defined(__sun)
   Field(v_tuple, 1) = val_file_type(e->d_type);
 #else
   Field(v_tuple, 1) = Val_int(7);
