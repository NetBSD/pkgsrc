$NetBSD: patch-util.c,v 1.1 2015/03/19 18:09:17 tnn Exp $

Workaround for bin/47757

--- util.c.orig	2014-12-10 19:40:54.000000000 +0000
+++ util.c
@@ -1063,6 +1063,9 @@ create_tmp_fd(char **fname)
 	char *template = format("%s.%s", *fname, tmp_string());
 	int fd = mkstemp(template);
 	if (fd == -1 && errno == ENOENT) {
+#if defined(__NetBSD__) && __NetBSD_Version__ < 700000000
+		reformat(&template, "%s.%s", *fname, tmp_string());
+#endif
 		if (create_parent_dirs(template) != 0) {
 			fatal("Failed to create directory %s: %s",
 			      dirname(template), strerror(errno));
@@ -1071,6 +1074,9 @@ create_tmp_fd(char **fname)
 		fd = mkstemp(template);
 	}
 	if (fd == -1) {
+#if defined(__NetBSD__) && __NetBSD_Version__ < 700000000
+		reformat(&template, "%s.%s", *fname, tmp_string());
+#endif
 		fatal("Failed to create file %s: %s", template, strerror(errno));
 	}
 
