$NetBSD: patch-src_klh10.c,v 1.1 2013/10/17 15:41:10 ryoon Exp $

http://www.falu.nl/~rhialto/klh-diffs2

--- src/klh10.c.orig	2005-02-21 23:20:34.000000000 +0000
+++ src/klh10.c
@@ -337,6 +337,7 @@ CMDDEF(cd_lights,  fc_lights,   CMRF_TLI
 KEYSBEGIN(fectbkeys)
     KEYDEF("?",		cd_ques)
     KEYDEF("help",	cd_help)
+    KEYDEF("exit",	cd_quit)
     KEYDEF("quit",	cd_quit)
     KEYDEF("load",	cd_load)
     KEYDEF("dump",	cd_dump)
@@ -2765,6 +2766,7 @@ fc_dump(struct cmd_s *cm)
 static void
 fc_lights(struct cmd_s *cm)
 {
+#if KLH10_DEV_LITES		/* Moby conditional for entire file */
     unsigned long port = 0;
     int c;
     char *sloc = cm->cmd_arglin;
@@ -2783,6 +2785,7 @@ fc_lights(struct cmd_s *cm)
 	}
     }
     printf("?Bad address\n");
+#endif /* KLH10_DEV_LITES */
 }
 
 /* Instruction printing routines */
