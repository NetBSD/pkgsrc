$NetBSD: patch-bplaysrc_shmbuf.c,v 1.1 2021/05/20 19:24:15 nia Exp $

Do not busy wait for confirmation after recording.
Patch from Debian:
https://sources.debian.org/patches/gramofile/1.6-12/20-no-busy-wait-after-rec.patch/

--- bplaysrc/shmbuf.c.orig	2000-03-27 21:38:56.000000000 +0000
+++ bplaysrc/shmbuf.c
@@ -443,7 +443,7 @@ printw(" %d",cbuff);
 	cleanupsems();
 
 #ifdef VUMETER
-	nodelay(stdscr, TRUE);
+	nodelay(stdscr, FALSE);
 
 	/* child has displayed informative data */
 	do
