$NetBSD: patch-tree.c,v 1.3 2014/04/29 07:07:26 wiz Exp $

Check for the symbol we're using.

--- tree.c.orig	2014-04-23 21:38:24.000000000 +0000
+++ tree.c
@@ -1258,7 +1258,7 @@ char Ftype(mode_t mode)
   else if (m == S_IFIFO) return '|';
   else if (m == S_IFLNK) return '@'; /* Here, but never actually used though. */
 #ifdef S_IFDOOR
-  else if (m == S_ISDOOR) return '>';
+  else if (m == S_IFDOOR) return '>';
 #endif
   else if ((m == S_IFREG) && (mode & (S_IXUSR | S_IXGRP | S_IXOTH))) return '*';
   return 0;
