$NetBSD: patch-lib_file_file.c,v 1.1 2016/10/09 03:41:56 ryoon Exp $

--- lib/file/file.c.orig	2016-02-16 20:06:45.000000000 +0000
+++ lib/file/file.c
@@ -1302,7 +1302,7 @@ File_MoveTree(const char *srcName,    //
          }
       }
 
-#if !defined(__FreeBSD__) && !defined(sun)
+#if !defined(__FreeBSD__) && !defined(sun) && !defined(__NetBSD__)
       /*
        * File_GetFreeSpace is not defined for FreeBSD
        */
