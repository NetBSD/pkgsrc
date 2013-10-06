$NetBSD: patch-plugins_symbol-db_anjuta-tags_main.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/symbol-db/anjuta-tags/main.c.orig	2013-09-29 15:17:33.000000000 +0000
+++ plugins/symbol-db/anjuta-tags/main.c
@@ -522,7 +522,7 @@ static void makeTags (cookedArgs *args)
  *		Start up code
  */
 
-extern int main (int __unused__ argc, char **argv)
+extern int main (int  argc, char **argv)
 {
 	cookedArgs *args;
 #ifdef VMS
