$NetBSD: patch-src_lib_vfs_ftpfs.cxx,v 1.1 2020/04/20 00:46:51 joerg Exp $

--- src/lib/vfs/ftpfs.cxx.orig	2020-04-19 23:46:16.047568214 +0000
+++ src/lib/vfs/ftpfs.cxx
@@ -1413,7 +1413,7 @@ void FTP::create_ftp_cachedir(char *dir)
                  return;
          if(strcmp(dir,"/"))
          {
-                 char *s=dir;
+                 const char *s=dir;
                  if(*s=='/')         //Skip leading '/'
                          s++;
                  do
