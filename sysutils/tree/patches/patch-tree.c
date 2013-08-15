$NetBSD: patch-tree.c,v 1.1 2013/08/15 12:40:06 richard Exp $

--- tree.c.orig	2011-06-24 14:26:30.000000000 +0000
+++ tree.c
@@ -45,7 +45,7 @@ int mb_cur_max;
 #ifdef __EMX__
 const u_short ifmt[]={ FILE_ARCHIVED, FILE_DIRECTORY, FILE_SYSTEM, FILE_HIDDEN, FILE_READONLY, 0};
 #else
-  #ifdef S_ISPORT
+  #if defined(S_ISPORT) && defined(S_ISDOOR)
   const u_int ifmt[] = {S_IFREG, S_IFDIR, S_IFLNK, S_IFCHR, S_IFBLK, S_IFSOCK, S_IFIFO, S_ISDOOR, S_ISPORT, 0};
   const char fmt[] = "-dlcbspDP?";
   const char *ftype[] = {"file", "directory", "link", "char", "block", "socket", "fifo", "door", "port", "unknown", NULL};
