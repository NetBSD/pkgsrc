$NetBSD: patch-src_filter.c,v 1.1 2016/01/07 12:05:31 wiz Exp $

Improve stdin-to-pipe hack on NetBSD
https://sourceforge.net/p/flex/bugs/198/

--- src/filter.c.orig	2015-11-10 23:10:20.000000000 +0000
+++ src/filter.c
@@ -174,6 +174,8 @@ clearerr(stdin);
 			flexfatal (_("dup2(pipes[0],0)"));
 		close (pipes[0]);
         fseek (stdin, 0, SEEK_CUR);
+        ungetc(' ', stdin); /* still an evil hack, but one that works better */
+        (void)fgetc(stdin); /* on NetBSD than the fseek attempt does */
 
 		/* run as a filter, either internally or by exec */
 		if (chain->filter_func) {
