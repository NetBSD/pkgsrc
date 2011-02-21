$NetBSD: patch-ext_zip_php__zip.c,v 1.1 2011/02/21 16:25:33 taca Exp $

Catch up to r308107 from PHP's repository.

--- ext/zip/php_zip.c.orig	2010-11-30 11:04:06.000000000 +0000
+++ ext/zip/php_zip.c
@@ -436,7 +436,7 @@ static int php_zip_extract_file(struct z
 			len = spprintf(&file_dirname_fullpath, 0, "%s/%s", dest, file_dirname);
 		}
 
-		php_basename(path_cleaned, path_cleaned_len, NULL, 0, &file_basename, (unsigned int *)&file_basename_len TSRMLS_CC);
+		php_basename(path_cleaned, path_cleaned_len, NULL, 0, &file_basename, &file_basename_len TSRMLS_CC);
 
 		if (OPENBASEDIR_CHECKPATH(file_dirname_fullpath)) {
 			efree(file_dirname_fullpath);
@@ -447,7 +447,7 @@ static int php_zip_extract_file(struct z
 	}
 
 	/* let see if the path already exists */
-	if (php_stream_stat_path(file_dirname_fullpath, &ssb) < 0) {
+	if (php_stream_stat_path_ex(file_dirname_fullpath, PHP_STREAM_URL_STAT_QUIET, &ssb, NULL) < 0) {
 
 #if defined(PHP_WIN32) && (PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION == 1)
 		char *e;
@@ -483,9 +483,14 @@ static int php_zip_extract_file(struct z
 		efree(file_dirname_fullpath);
 		efree(file_basename);
 		free(new_state.cwd);
+		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Cannot build full extract path");
 		return 0;
 	} else if (len > MAXPATHLEN) {
 		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Full extraction path exceed MAXPATHLEN (%i)", MAXPATHLEN);
+		efree(file_dirname_fullpath);
+		efree(file_basename);
+		free(new_state.cwd);
+		return 0;
 	}
 
 	/* check again the full path, not sure if it
@@ -500,27 +505,42 @@ static int php_zip_extract_file(struct z
 		return 0;
 	}
 
+#if PHP_API_VERSION < 20100412
+	stream = php_stream_open_wrapper(fullpath, "w+b", REPORT_ERRORS|ENFORCE_SAFE_MODE, NULL);
+#else
+	stream = php_stream_open_wrapper(fullpath, "w+b", REPORT_ERRORS, NULL);
+#endif
+
+	if (stream == NULL) {
+		n = -1;
+		goto done;
+	}
+
 	zf = zip_fopen(za, file, 0);
 	if (zf == NULL) {
+		n = -1;
+		php_stream_close(stream);
+		goto done;
+	}
+
+	n = 0;
+	if (stream == NULL) {
+		int ret = zip_fclose(zf);
 		efree(fullpath);
-		efree(file_dirname_fullpath);
 		efree(file_basename);
+		efree(file_dirname_fullpath);
 		free(new_state.cwd);
 		return 0;
 	}
 
-#if (PHP_MAJOR_VERSION < 6)
-	stream = php_stream_open_wrapper(fullpath, "w+b", REPORT_ERRORS|ENFORCE_SAFE_MODE, NULL);
-#else
-	stream = php_stream_open_wrapper(fullpath, "w+b", REPORT_ERRORS, NULL);
-#endif
-	n = 0;
-	if (stream) {
-		while ((n=zip_fread(zf, b, sizeof(b))) > 0) php_stream_write(stream, b, n);
-		php_stream_close(stream);
+	while ((n=zip_fread(zf, b, sizeof(b))) > 0) {
+		php_stream_write(stream, b, n);
 	}
+
+	php_stream_close(stream);
 	n = zip_fclose(zf);
 
+done:
 	efree(fullpath);
 	efree(file_basename);
 	efree(file_dirname_fullpath);
