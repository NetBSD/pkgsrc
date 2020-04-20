$NetBSD: patch-src_lib_vfs_afs.cxx,v 1.1 2020/04/20 00:46:51 joerg Exp $

--- src/lib/vfs/afs.cxx.orig	2020-04-19 23:44:54.825370720 +0000
+++ src/lib/vfs/afs.cxx
@@ -29,7 +29,7 @@ int    dont_update = 0;                /
 // The return value is static, so copy it before using the
 // method again!
 
-char *create_dirs(char *rootdir, char* dirlist)
+char *create_dirs(char *rootdir, const char* dirlist)
 {
    char str[L_MAXPATH];
    char cont[FLIST_NAME];
@@ -1350,7 +1350,7 @@ int    AFS::direc(char *dir_ch)
     add_path_content(curdir, to_dir);
   } else        //If we here then we doing cd not to subdir but to subdir/subdir...
   {
-    char *s=to_dir;
+    const char *s=to_dir;
     if(*s)
     {
       do
