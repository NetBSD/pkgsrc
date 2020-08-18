$NetBSD: patch-lib_files.c,v 1.1 2020/08/18 01:46:07 tnn Exp $

files.c:128:35: error: '__builtin_snprintf' output may be truncated before the last format character [-Werror=format-truncation=]
  snprintf(buffer, sizeof(buffer), "%s/%s" , path, connection_filename);
                                   ^~~~~~~
files.c:128:2: note: '__builtin_snprintf' output 2 or more bytes (assuming 257) into a destination of size 256
  snprintf(buffer, sizeof(buffer), "%s/%s" , path, connection_filename);

--- lib/files.c.orig	2005-05-16 21:42:34.000000000 +0000
+++ lib/files.c
@@ -125,7 +125,8 @@ bool synce_get_connection_filename(char*
 	if (!synce_get_directory(&path))
 		goto exit;
 
-	snprintf(buffer, sizeof(buffer), "%s/%s" , path, connection_filename);
+	if (snprintf(buffer, sizeof(buffer), "%s/%s" , path, connection_filename) > (int)sizeof(buffer) - 1)
+		goto exit;
 	*filename = strdup(buffer);
 
 	success = true;
