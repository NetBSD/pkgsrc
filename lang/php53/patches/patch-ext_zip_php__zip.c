$NetBSD: patch-ext_zip_php__zip.c,v 1.1.2.2 2011/02/23 19:12:54 tron Exp $

Catch up to r308107 from PHP's repository.

--- ext/zip/php_zip.c.orig	2010-11-30 11:04:06.000000000 +0000
+++ ext/zip/php_zip.c
@@ -196,7 +196,7 @@ static int php_zip_extract_file(struct z
 	}
 
 	/* let see if the path already exists */
-	if (php_stream_stat_path(file_dirname_fullpath, &ssb) < 0) {
+	if (php_stream_stat_path_ex(file_dirname_fullpath, PHP_STREAM_URL_STAT_QUIET, &ssb, NULL) < 0) {
 
 #if defined(PHP_WIN32) && (PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION == 1)
 		char *e;
@@ -232,9 +232,14 @@ static int php_zip_extract_file(struct z
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
@@ -249,27 +254,42 @@ static int php_zip_extract_file(struct z
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
 
-#if PHP_API_VERSION < 20100412
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
@@ -473,10 +493,12 @@ static char * php_zipobj_get_zip_comment
 #define GLOB_FLAGMASK (~GLOB_ONLYDIR)
 #else
 #define GLOB_FLAGMASK (~0)
+#endif
 #endif /* }}} */
 
 int php_zip_glob(char *pattern, int pattern_len, long flags, zval *return_value TSRMLS_DC) /* {{{ */
 {
+#ifdef HAVE_GLOB
 	char cwd[MAXPATHLEN];
 	int cwd_skip = 0;
 #ifdef ZTS
@@ -563,6 +585,10 @@ int php_zip_glob(char *pattern, int patt
 
 	globfree(&globbuf);
 	return globbuf.gl_pathc;
+#else
+	php_error_docref(NULL TSRMLS_CC, E_ERROR, "Glob support is not available");
+	return 0;
+#endif  /* HAVE_GLOB */
 }
 /* }}} */
 
@@ -664,7 +690,6 @@ int php_zip_pcre(char *regexp, int regex
 	return files_cnt;
 }
 /* }}} */
-#endif 
 
 #endif
 
@@ -1688,7 +1713,7 @@ static void php_zip_add_from_pattern(INT
 }
 /* }}} */
 
-/* {{{ proto bool addGlob(string pattern[,int flags [, array options]])
+/* {{{ proto bool ZipArchive::addGlob(string pattern[,int flags [, array options]])
 Add files matching the glob pattern. See php's glob for the pattern syntax. */
 static ZIPARCHIVE_METHOD(addGlob)
 {
@@ -1696,7 +1721,7 @@ static ZIPARCHIVE_METHOD(addGlob)
 }
 /* }}} */
 
-/* {{{ proto bool addPattern(string pattern[, string path [, array options]])
+/* {{{ proto bool ZipArchive::addPattern(string pattern[, string path [, array options]])
 Add files matching the pcre pattern. See php's pcre for the pattern syntax. */
 static ZIPARCHIVE_METHOD(addPattern)
 {
@@ -1925,7 +1950,7 @@ static ZIPARCHIVE_METHOD(getNameIndex)
 }
 /* }}} */
 
-/* {{{ proto bool ZipArchive::setArchiveComment(string name, string comment)
+/* {{{ proto bool ZipArchive::setArchiveComment(string comment)
 Set or remove (NULL/'') the comment of the archive */
 static ZIPARCHIVE_METHOD(setArchiveComment)
 {
@@ -1951,7 +1976,7 @@ static ZIPARCHIVE_METHOD(setArchiveComme
 }
 /* }}} */
 
-/* {{{ proto string ZipArchive::getArchiveComment()
+/* {{{ proto string ZipArchive::getArchiveComment([int flags])
 Returns the comment of an entry using its index */
 static ZIPARCHIVE_METHOD(getArchiveComment)
 {
@@ -2039,7 +2064,7 @@ static ZIPARCHIVE_METHOD(setCommentIndex
 }
 /* }}} */
 
-/* {{{ proto string ZipArchive::getCommentName(string name)
+/* {{{ proto string ZipArchive::getCommentName(string name[, int flags])
 Returns the comment of an entry using its name */
 static ZIPARCHIVE_METHOD(getCommentName)
 {
@@ -2076,7 +2101,7 @@ static ZIPARCHIVE_METHOD(getCommentName)
 }
 /* }}} */
 
-/* {{{ proto string ZipArchive::getCommentIndex(int index)
+/* {{{ proto string ZipArchive::getCommentIndex(int index[, int flags])
 Returns the comment of an entry using its index */
 static ZIPARCHIVE_METHOD(getCommentIndex)
 {
@@ -2378,7 +2403,7 @@ static ZIPARCHIVE_METHOD(extractTo)
 		RETURN_FALSE;
 	}
 
-	if (php_stream_stat_path(pathto, &ssb) < 0) {
+	if (php_stream_stat_path_ex(pathto, PHP_STREAM_URL_STAT_QUIET, &ssb, NULL) < 0) {
 		ret = php_stream_mkdir(pathto, 0777,  PHP_STREAM_MKDIR_RECURSIVE, NULL);
 		if (!ret) {
 			RETURN_FALSE;
@@ -2559,7 +2584,7 @@ static ZIPARCHIVE_METHOD(getStream)
 
 /* {{{ arginfo */
 ZEND_BEGIN_ARG_INFO_EX(arginfo_ziparchive_open, 0, 0, 1)
-	ZEND_ARG_INFO(0, source)
+	ZEND_ARG_INFO(0, filename)
 	ZEND_ARG_INFO(0, flags)
 ZEND_END_ARG_INFO()
 
@@ -2604,8 +2629,7 @@ ZEND_BEGIN_ARG_INFO_EX(arginfo_ziparchiv
 	ZEND_ARG_INFO(0, flags)
 ZEND_END_ARG_INFO()
 
-ZEND_BEGIN_ARG_INFO_EX(arginfo_ziparchive_setarchivecomment, 0, 0, 2)
-	ZEND_ARG_INFO(0, name)
+ZEND_BEGIN_ARG_INFO_EX(arginfo_ziparchive_setarchivecomment, 0, 0, 1)
 	ZEND_ARG_INFO(0, comment)
 ZEND_END_ARG_INFO()
 
@@ -2616,10 +2640,12 @@ ZEND_END_ARG_INFO()
 
 ZEND_BEGIN_ARG_INFO_EX(arginfo_ziparchive_getcommentname, 0, 0, 1)
 	ZEND_ARG_INFO(0, name)
+	ZEND_ARG_INFO(0, flags)
 ZEND_END_ARG_INFO()
 
 ZEND_BEGIN_ARG_INFO_EX(arginfo_ziparchive_getcommentindex, 0, 0, 1)
 	ZEND_ARG_INFO(0, index)
+	ZEND_ARG_INFO(0, flags)
 ZEND_END_ARG_INFO()
 
 ZEND_BEGIN_ARG_INFO_EX(arginfo_ziparchive_renameindex, 0, 0, 2)
@@ -2657,6 +2683,15 @@ ZEND_BEGIN_ARG_INFO_EX(arginfo_ziparchiv
 	ZEND_ARG_INFO(0, flags)
 ZEND_END_ARG_INFO()
 
+ZEND_BEGIN_ARG_INFO_EX(arginfo_ziparchive_getarchivecomment, 0, 0, 0)
+	ZEND_ARG_INFO(0, flags)
+ZEND_END_ARG_INFO()
+
+ZEND_BEGIN_ARG_INFO_EX(arginfo_ziparchive_setcommentname, 0, 0, 2)
+	ZEND_ARG_INFO(0, name)
+	ZEND_ARG_INFO(0, comment)
+ZEND_END_ARG_INFO()
+
 ZEND_BEGIN_ARG_INFO_EX(arginfo_ziparchive_getstream, 0, 0, 1)
 	ZEND_ARG_INFO(0, entryname)
 ZEND_END_ARG_INFO()
@@ -2675,21 +2710,21 @@ static const zend_function_entry zip_cla
 	ZIPARCHIVE_ME(renameIndex,			arginfo_ziparchive_renameindex, ZEND_ACC_PUBLIC)
 	ZIPARCHIVE_ME(renameName,			arginfo_ziparchive_renamename, ZEND_ACC_PUBLIC)
 	ZIPARCHIVE_ME(setArchiveComment,	arginfo_ziparchive_setarchivecomment, ZEND_ACC_PUBLIC)
-	ZIPARCHIVE_ME(getArchiveComment,	arginfo_ziparchive__void, ZEND_ACC_PUBLIC)
+	ZIPARCHIVE_ME(getArchiveComment,	arginfo_ziparchive_getarchivecomment, ZEND_ACC_PUBLIC)
 	ZIPARCHIVE_ME(setCommentIndex,		arginfo_ziparchive_setcommentindex, ZEND_ACC_PUBLIC)
-	ZIPARCHIVE_ME(setCommentName,		arginfo_ziparchive_setarchivecomment, ZEND_ACC_PUBLIC)
+	ZIPARCHIVE_ME(setCommentName,		arginfo_ziparchive_setcommentname, ZEND_ACC_PUBLIC)
 	ZIPARCHIVE_ME(getCommentIndex,		arginfo_ziparchive_getcommentindex, ZEND_ACC_PUBLIC)
 	ZIPARCHIVE_ME(getCommentName,		arginfo_ziparchive_getcommentname, ZEND_ACC_PUBLIC)
-	ZIPARCHIVE_ME(deleteIndex,			arginfo_ziparchive_getcommentindex, ZEND_ACC_PUBLIC)
-	ZIPARCHIVE_ME(deleteName,			arginfo_ziparchive_getcommentname, ZEND_ACC_PUBLIC)
+	ZIPARCHIVE_ME(deleteIndex,			arginfo_ziparchive_unchangeindex, ZEND_ACC_PUBLIC)
+	ZIPARCHIVE_ME(deleteName,			arginfo_ziparchive_unchangename, ZEND_ACC_PUBLIC)
 	ZIPARCHIVE_ME(statName,				arginfo_ziparchive_statname, ZEND_ACC_PUBLIC)
 	ZIPARCHIVE_ME(statIndex,			arginfo_ziparchive_statindex, ZEND_ACC_PUBLIC)
 	ZIPARCHIVE_ME(locateName,			arginfo_ziparchive_statname, ZEND_ACC_PUBLIC)
 	ZIPARCHIVE_ME(getNameIndex,			arginfo_ziparchive_statindex, ZEND_ACC_PUBLIC)
 	ZIPARCHIVE_ME(unchangeArchive,		arginfo_ziparchive__void, ZEND_ACC_PUBLIC)
 	ZIPARCHIVE_ME(unchangeAll,			arginfo_ziparchive__void, ZEND_ACC_PUBLIC)
-	ZIPARCHIVE_ME(unchangeIndex,		arginfo_ziparchive_getcommentindex, ZEND_ACC_PUBLIC)
-	ZIPARCHIVE_ME(unchangeName,			arginfo_ziparchive_getcommentname, ZEND_ACC_PUBLIC)
+	ZIPARCHIVE_ME(unchangeIndex,		arginfo_ziparchive_unchangeindex, ZEND_ACC_PUBLIC)
+	ZIPARCHIVE_ME(unchangeName,			arginfo_ziparchive_unchangename, ZEND_ACC_PUBLIC)
 	ZIPARCHIVE_ME(extractTo,			arginfo_ziparchive_extractto, ZEND_ACC_PUBLIC)
 	ZIPARCHIVE_ME(getFromName,			arginfo_ziparchive_getfromname, ZEND_ACC_PUBLIC)
 	ZIPARCHIVE_ME(getFromIndex,			arginfo_ziparchive_getfromindex, ZEND_ACC_PUBLIC)
@@ -2744,6 +2779,12 @@ static PHP_MINIT_FUNCTION(zip)
 	REGISTER_ZIP_CLASS_CONST_LONG("CM_DEFLATE", ZIP_CM_DEFLATE);
 	REGISTER_ZIP_CLASS_CONST_LONG("CM_DEFLATE64", ZIP_CM_DEFLATE64);
 	REGISTER_ZIP_CLASS_CONST_LONG("CM_PKWARE_IMPLODE", ZIP_CM_PKWARE_IMPLODE);
+	REGISTER_ZIP_CLASS_CONST_LONG("CM_BZIP2", ZIP_CM_BZIP2);
+	REGISTER_ZIP_CLASS_CONST_LONG("CM_LZMA", ZIP_CM_LZMA);
+	REGISTER_ZIP_CLASS_CONST_LONG("CM_TERSE", ZIP_CM_TERSE);
+	REGISTER_ZIP_CLASS_CONST_LONG("CM_LZ77", ZIP_CM_LZ77);
+	REGISTER_ZIP_CLASS_CONST_LONG("CM_WAVPACK", ZIP_CM_WAVPACK);
+	REGISTER_ZIP_CLASS_CONST_LONG("CM_PPMD", ZIP_CM_PPMD);
 
 	/* Error code */
 	REGISTER_ZIP_CLASS_CONST_LONG("ER_OK",			ZIP_ER_OK);			/* N No error */
