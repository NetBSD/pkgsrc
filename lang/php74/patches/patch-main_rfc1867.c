$NetBSD: patch-main_rfc1867.c,v 1.1 2026/10/22 02:06:46 taca Exp $

Fix for CVE-2026-109618-109619.

--- main/rfc1867.c.orig	2022-10-31 10:36:05.000000000 +0000
+++ main/rfc1867.c
@@ -397,6 +397,14 @@ static int find_boundary(multipart_buffe
 	return 0;
 }
 
+static zend_bool php_mime_should_save_hdr(const char *name)
+{
+	return !strcasecmp(name, "Content-Disposition")
+		|| !strcasecmp(name, "Content-Type");
+}
+
+static char *php_mime_get_hdr_value(zend_llist header, char *key);
+
 /* parse headers */
 static int multipart_buffer_headers(multipart_buffer *self, zend_llist *header)
 {
@@ -437,10 +445,16 @@ static int multipart_buffer_headers(mult
 			}
 
 			*value = '\0';
-			do { value++; } while (isspace(*value));
 
+			/* Keep only headers we use, and ignore duplicates */
+			if (!php_mime_should_save_hdr(line)
+					|| php_mime_get_hdr_value(*header, line)) {
+				key = NULL;
+			} else {
 			key = estrdup(line);
+				do { value++; } while (isspace((unsigned char)*value));
 			smart_string_appends(&buf_value, value);
+			}
 		} else if (buf_value.c) { /* If no ':' on the line, add to previous line */
 			smart_string_appends(&buf_value, line);
 		} else {
@@ -514,11 +528,11 @@ static char *php_ap_getword(const zend_e
 	return res;
 }
 
-static char *substring_conf(char *start, int len, char quote)
+static char *substring_conf(char *start, size_t len, char quote)
 {
 	char *result = emalloc(len + 1);
 	char *resp = result;
-	int i;
+	size_t i;
 
 	for (i = 0; i < len && start[i] != quote; ++i) {
 		if (start[i] == '\\' && (start[i + 1] == '\\' || (quote && start[i + 1] == quote))) {
@@ -546,14 +560,14 @@ static char *php_ap_getword_conf(const z
 		char quote = *str;
 
 		str++;
-		return substring_conf(str, (int)strlen(str), quote);
+		return substring_conf(str, strlen(str), quote);
 	} else {
 		char *strend = str;
 
 		while (*strend && !isspace(*strend)) {
 			++strend;
 		}
-		return substring_conf(str, strend - str, 0);
+		return substring_conf(str, (size_t)(strend - str), 0);
 	}
 }
 
@@ -694,6 +708,7 @@ SAPI_API SAPI_POST_HANDLER_FUNC(rfc1867_
 	void *event_extra_data = NULL;
 	unsigned int llen = 0;
 	int upload_cnt = INI_INT("max_file_uploads");
+	int body_parts_cnt = INI_INT("max_multipart_body_parts");
 	const zend_encoding *internal_encoding = zend_multibyte_get_internal_encoding();
 	php_rfc1867_getword_t getword;
 	php_rfc1867_getword_conf_t getword_conf;
@@ -715,6 +730,11 @@ SAPI_API SAPI_POST_HANDLER_FUNC(rfc1867_
 		return;
 	}
 
+	if (body_parts_cnt < 0) {
+		body_parts_cnt = PG(max_input_vars) + upload_cnt;
+	}
+	int body_parts_limit = body_parts_cnt;
+
 	/* Get the boundary */
 	boundary = strstr(content_type_dup, "boundary");
 	if (!boundary) {
@@ -799,6 +819,11 @@ SAPI_API SAPI_POST_HANDLER_FUNC(rfc1867_
 			char *pair = NULL;
 			int end = 0;
 
+			if (--body_parts_cnt < 0) {
+				php_error_docref(NULL, E_WARNING, "Multipart body parts limit exceeded %d. To increase the limit change max_multipart_body_parts in php.ini.", body_parts_limit);
+				goto fileupload_done;
+			}
+
 			while (isspace(*cd)) {
 				++cd;
 			}
