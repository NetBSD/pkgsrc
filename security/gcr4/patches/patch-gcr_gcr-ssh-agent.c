$NetBSD: patch-gcr_gcr-ssh-agent.c,v 1.1 2026/05/03 09:51:11 vins Exp $

Honor the actual ssh-agent's binary name.

--- gcr/gcr-ssh-agent.c.orig	2026-05-03 08:07:50.857445299 +0000
+++ gcr/gcr-ssh-agent.c
@@ -61,12 +61,12 @@ main (int argc,
         parse_arguments(&argc, &argv);
 
 	if (!base_dir) {
-		g_printerr ("Usage: gcr-ssh-agent --base-dir <base-dir> --\n");
+		g_printerr ("Usage: gcr4-ssh-agent --base-dir <base-dir> --\n");
 		return EXIT_FAILURE;
 	}
 
 	if (!g_path_is_absolute (base_dir)) {
-		g_printerr ("gcr-ssh-agent: base-dir must be specified as an absolute path\n");
+		g_printerr ("gcr4-ssh-agent: base-dir must be specified as an absolute path\n");
 		return EXIT_FAILURE;
 	}
 
