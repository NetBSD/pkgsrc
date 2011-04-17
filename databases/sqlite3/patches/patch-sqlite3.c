$NetBSD: patch-sqlite3.c,v 1.1 2011/04/17 09:14:13 adam Exp $

Fix open() signature.

--- sqlite3.c.orig	2011-04-17 08:42:16.000000000 +0000
+++ sqlite3.c
@@ -24413,7 +24413,7 @@ static struct unix_syscall {
   sqlite3_syscall_ptr pDefault; /* Default value */
 } aSyscall[] = {
   { "open",         (sqlite3_syscall_ptr)open,       0  },
-#define osOpen      ((int(*)(const char*,int,int))aSyscall[0].pCurrent)
+#define osOpen      ((int(*)(const char*,int,...))aSyscall[0].pCurrent)
 
   { "close",        (sqlite3_syscall_ptr)close,      0  },
 #define osClose     ((int(*)(int))aSyscall[1].pCurrent)
