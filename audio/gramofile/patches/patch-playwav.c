$NetBSD: patch-playwav.c,v 1.1 2021/05/20 19:24:15 nia Exp $

fix shell quoting. from Debian:
https://sources.debian.org/patches/gramofile/1.6-12/20-shell-quoting.patch/
Patch by Jon Schewe <jpschewe@eggplant.mtu.net>

--- playwav.c.orig	2000-03-28 21:07:25.000000000 +0000
+++ playwav.c
@@ -44,11 +44,11 @@ playwav_playit (char *filename, int useb
     case FILE_EXISTS:
 
       if (usebeginendtime)
-	sprintf (shellcmd, "bplay_gramo -S -s 44100 -b 16 -J %ld -T %ld %s",
+	sprintf (shellcmd, "bplay_gramo -S -s 44100 -b 16 -J %ld -T %ld \"%s\"",
 		 (long) (begintime * 44100),
 		 (long) ((endtime - begintime) * 44100), filename);
       else
-	sprintf (shellcmd, "bplay_gramo -S -s 44100 -b 16 %s", filename);
+	sprintf (shellcmd, "bplay_gramo -S -s 44100 -b 16 \"%s\"", filename);
       /* defaults for raw files (but no -r, so .wav's supply their own
          parameters) - you can even listen to executables in CD quality (: */
 
@@ -771,11 +771,11 @@ playwav_main (char *startdir)
       def_prog_mode ();		/* save terminal state */
 
       if (usebeginendtime)
-	sprintf (shellcmd, "bplay_gramo -S -s 44100 -b 16 -J %ld -T %ld %s",
+	sprintf (shellcmd, "bplay_gramo -S -s 44100 -b 16 -J %ld -T %ld \"%s\"",
 		 (long) (begintime * 44100),
 		 (long) ((endtime - begintime) * 44100), filename);
       else
-	sprintf (shellcmd, "bplay_gramo -S -s 44100 -b 16 %s", filename);
+	sprintf (shellcmd, "bplay_gramo -S -s 44100 -b 16 \"%s\"", filename);
       /* defaults for raw files (but no -r, so .wav's supply their own
          parameters */
 
