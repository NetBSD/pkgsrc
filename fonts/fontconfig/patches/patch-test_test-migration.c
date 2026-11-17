$NetBSD: patch-test_test-migration.c,v 1.5 2026/11/17 16:58:52 wiz Exp $

Fix build on SCO OpenServer 5.0.7/3.2.

--- test/test-migration.c.orig	2014-01-20 08:14:21.000000000 +0000
+++ test/test-migration.c
@@ -153,8 +153,10 @@ main(void)
 
     strcpy (xdg, tmp);
     strcpy (&xdg[len], "/.config");
+#if !defined(_SCO_DS) /* SCO OpenServer 5.0.7/3.2 has no setenv. */
     setenv ("HOME", tmp, 1);
     setenv ("XDG_CONFIG_HOME", xdg, 1);
+#endif
     xlen = strlen (xdg);
     strcpy (confd, xdg);
     strcpy (&confd[xlen], "/fontconfig");
