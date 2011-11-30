$NetBSD: patch-lib-src_emacsclient.c,v 1.1 2011/11/30 04:29:10 minskim Exp $

--- lib-src/emacsclient.c.orig	2011-11-28 09:24:08.000000000 +0000
+++ lib-src/emacsclient.c
@@ -1635,6 +1635,7 @@ main (int argc, char **argv)
   /* Send over our environment and current directory. */
   if (!current_frame)
     {
+      extern char **environ;
       int i;
       for (i = 0; environ[i]; i++)
         {
