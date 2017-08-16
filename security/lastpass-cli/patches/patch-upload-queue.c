$NetBSD: patch-upload-queue.c,v 1.1 2017/08/16 15:18:24 jperkin Exp $

SunOS compatibility.

--- upload-queue.c.orig	2017-06-28 12:50:49.000000000 +0000
+++ upload-queue.c
@@ -110,8 +110,12 @@ static void upload_queue_cleanup_failure
 
 	while ((entry = readdir(dir))) {
 		_cleanup_free_ char *fn = NULL;
-
+#ifdef __sun
+		stat(entry->d_name, &sbuf);
+		if (sbuf.st_mode != S_IFREG)
+#else
 		if (entry->d_type != DT_REG && entry->d_type != DT_UNKNOWN)
+#endif
 			continue;
 
 		for (p = entry->d_name; *p; ++p) {
@@ -172,11 +176,19 @@ static char *upload_queue_next_entry(uns
 	char *result, *p;
 	DIR *dir = opendir(base_path);
 	struct dirent *entry;
+#ifdef __sun
+	struct stat s;
+#endif
 
 	if (!dir)
 		return NULL;
 	while ((entry = readdir(dir))) {
+#ifdef __sun
+		stat(entry->d_name, &s);
+		if (s.st_mode != S_IFREG)
+#else
 		if (entry->d_type != DT_REG && entry->d_type != DT_UNKNOWN)
+#endif
 			continue;
 
 		for (p = entry->d_name; *p; ++p) {
