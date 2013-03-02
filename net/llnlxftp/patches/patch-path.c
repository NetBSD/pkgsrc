$NetBSD: patch-path.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- path.c.orig	1995-10-19 15:20:23.000000000 +0000
+++ path.c
@@ -300,8 +300,7 @@ char *path;
 /*
  * release_path_links - Release the memory returned by path_to_links().
  */
-release_path_links(links)
-char **links;
+void release_path_links(char **links)
 {
 	char **ptr = links;
 	
