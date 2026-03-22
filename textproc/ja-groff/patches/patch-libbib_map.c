$NetBSD: patch-libbib_map.c,v 1.1 2026/03/22 10:34:03 nia Exp $

Fix implicit declaration of abort(3).

--- libbib/map.c.orig	2026-03-22 10:10:46.962197951 +0000
+++ libbib/map.c
@@ -21,6 +21,7 @@ Foundation, 59 Temple Place - Suite 330,
 
 #include <sys/types.h>
 #include <sys/mman.h>
+#include <stdlib.h>
 
 /* The Net-2 man pages says that a MAP_FILE flag is required. */
 #ifndef MAP_FILE
