$NetBSD: patch-phoenix_info.c,v 1.1 2015/10/25 09:05:23 bouyer Exp $
fix uninitialised variable use

--- phoenix_info.c.orig	2015-10-24 23:20:32.000000000 +0200
+++ phoenix_info.c	2015-10-24 23:22:06.000000000 +0200
@@ -45,7 +45,7 @@
 {
 	int l = strlen(dest) + 16;
 	char outname[l];
-	FILE *out;
+	FILE *out = NULL;
 	char *buf = NULL;
 	int ret = 0;
 	snprintf(outname, l, dest, part);
@@ -72,7 +72,7 @@
 _exit:
 	if (buf)
 		free(buf);
-	if (out != stdout)
+	if (out != NULL && out != stdout)
 		fclose(out);
 	return ret;
 err:
