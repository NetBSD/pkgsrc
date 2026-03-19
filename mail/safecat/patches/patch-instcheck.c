$NetBSD: patch-instcheck.c,v 1.1 2026/03/19 07:50:46 nia Exp $

Fix implicit function declarations.

--- instcheck.c.orig	2026-03-19 07:33:03.286024914 +0000
+++ instcheck.c
@@ -1,5 +1,6 @@
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <unistd.h>
 #include "strerr.h"
 #include "error.h"
 #include "readwrite.h"
@@ -101,6 +102,7 @@ int mode;
   perm("",home,"/",file,S_IFREG,uid,gid,mode);
 }
 
+int
 main()
 {
   hier();
