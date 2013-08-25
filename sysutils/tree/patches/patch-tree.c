$NetBSD: patch-tree.c,v 1.2 2013/08/25 14:29:52 richard Exp $

* ensure that both S_ISPORT and S_ISDOOR are defined prior to ifmt
* declaration.
*
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
