$NetBSD: patch-pkgsrc__user__destdir__fake__chown.c,v 1.1 2017/03/20 16:23:20 schmonz Exp $

Install files without needing real qmail users to exist yet.

--- pkgsrc_user_destdir_fake_chown.c.orig	2017-03-20 13:51:05.000000000 +0000
+++ pkgsrc_user_destdir_fake_chown.c
@@ -0,0 +1,8 @@
+int chown(path,owner,group)
+const char *path;
+unsigned int owner;
+unsigned int group;
+{
+  /* pkgsrc: can't chown in stage-install, will chown on install */
+  return 0;
+}
