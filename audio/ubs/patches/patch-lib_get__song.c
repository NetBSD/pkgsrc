$NetBSD: patch-lib_get__song.c,v 1.1 2012/03/01 17:30:01 hans Exp $

--- lib/get_song.c.orig	2003-10-29 06:17:10.000000000 +0100
+++ lib/get_song.c	2012-03-01 18:17:56.807135414 +0100
@@ -22,7 +22,7 @@ Foundation, Inc., 59 Temple Place, Suite
 #include <string.h>
 #include <dirent.h>
 #include <sys/types.h>
-#include <sys/dir.h>
+#include <dirent.h>
 #include <sys/param.h>
 #include <sys/stat.h>
 
