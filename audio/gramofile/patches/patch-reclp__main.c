$NetBSD: patch-reclp__main.c,v 1.1 2021/05/20 19:24:15 nia Exp $

Shell quoting fixes from Debian:
https://sources.debian.org/patches/gramofile/1.6-12/20-shell-quoting.patch/
Patch by Jon Schewe <jpschewe@eggplant.mtu.net>

--- reclp_main.c.orig	2000-03-28 21:07:25.000000000 +0000
+++ reclp_main.c
@@ -30,7 +30,7 @@ record_from_lp (char *startdir)
 
   def_prog_mode ();		/* save terminal state */
 
-  sprintf (shellcmd, "brec_gramo -S -s 44100 -b 16 -t 6000 -w %s",
+  sprintf (shellcmd, "brec_gramo -S -s 44100 -b 16 -t 6000 -w \"%s\"",
 	   filename);
   system (shellcmd);
 
