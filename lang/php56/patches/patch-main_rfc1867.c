$NetBSD: patch-main_rfc1867.c,v 1.1 2026/10/27 15:30:49 taca Exp $

https://raw.githubusercontent.com/Anton-Barinov/php2shell-patches/refs/heads/main/patches/php-5.6-enhanced-universal.patch

--- main/rfc1867.c.orig	2019-01-09 09:54:13.000000000 +0000
+++ main/rfc1867.c
@@ -249,6 +249,12 @@ static int fill_buffer(multipart_buffer 
 
 	self->buf_begin = self->buffer;
 
+	/* The declared Content-Length was checked against post_max_size, but the
+	 * body may be longer (or chunked) */
+	if (SG(post_max_size) > 0 && SG(read_post_bytes) > SG(post_max_size)) {
+		return 0;
+	}
+
 	/* calculate the free space in the buffer */
 	bytes_to_read = self->bufsize - self->bytes_in_buffer;
 
@@ -400,6 +406,14 @@ static int find_boundary(multipart_buffe
 	return 0;
 }
 
+static char *php_mime_get_hdr_value(zend_llist header, char *key);
+
+static zend_bool php_mime_should_save_hdr(const char *name)
+{
+	return !strcasecmp(name, "Content-Disposition")
+		|| !strcasecmp(name, "Content-Type");
+}
+
 /* parse headers */
 static int multipart_buffer_headers(multipart_buffer *self, zend_llist *header TSRMLS_DC)
 {
@@ -441,15 +455,31 @@ static int multipart_buffer_headers(mult
 			}
 
 			*value = '\0';
-			do { value++; } while(isspace(*value));
 
-			key = estrdup(line);
-			smart_str_appends(&buf_value, value);
+			/* An unbounded number of headers would be kept in memory: keep
+			 * only the ones we use, and ignore duplicates */
+			if (!php_mime_should_save_hdr(line)
+					|| php_mime_get_hdr_value(*header, line)) {
+				key = NULL;
+			} else {
+				do { value++; } while(isspace(*value));
+
+				key = estrdup(line);
+				smart_str_appends(&buf_value, value);
+			}
 		} else if (buf_value.c) { /* If no ':' on the line, add to previous line */
 			smart_str_appends(&buf_value, line);
 		} else {
 			continue;
 		}
+
+		if (ZEND_HAS_OOM()) {
+			if (key) {
+				efree(key);
+			}
+			smart_str_free(&buf_value);
+			return 0;
+		}
 	}
 	if(buf_value.c && key) {
 		/* add the last one to the list */
@@ -664,6 +694,9 @@ static char *multipart_buffer_read_body(
 		out = erealloc(out, total_bytes + read_bytes + 1);
 		memcpy(out + total_bytes, buf, read_bytes);
 		total_bytes += read_bytes;
+		if (ZEND_HAS_OOM()) {
+			break;
+		}
 	}
 
 	if (out) {
@@ -696,6 +729,8 @@ SAPI_API SAPI_POST_HANDLER_FUNC(rfc1867_
 	void *event_extra_data = NULL;
 	unsigned int llen = 0;
 	int upload_cnt = INI_INT("max_file_uploads");
+	long body_parts_cnt = INI_INT("max_multipart_body_parts");
+	long body_parts_limit;
 	const zend_encoding *internal_encoding = zend_multibyte_get_internal_encoding(TSRMLS_C);
 	php_rfc1867_getword_t getword;
 	php_rfc1867_getword_conf_t getword_conf;
@@ -717,6 +752,11 @@ SAPI_API SAPI_POST_HANDLER_FUNC(rfc1867_
 		return;
 	}
 
+	if (body_parts_cnt < 0) {
+		body_parts_cnt = PG(max_input_vars) + upload_cnt;
+	}
+	body_parts_limit = body_parts_cnt;
+
 	/* Get the boundary */
 	boundary = strstr(content_type_dup, "boundary");
 	if (!boundary) {
@@ -782,6 +822,9 @@ SAPI_API SAPI_POST_HANDLER_FUNC(rfc1867_
 		if (php_rfc1867_callback(MULTIPART_EVENT_START, &event_start, &event_extra_data TSRMLS_CC) == FAILURE) {
 			goto fileupload_done;
 		}
+		if (ZEND_HAS_OOM()) {
+			goto fileupload_done;
+		}
 	}
 
 	while (!multipart_buffer_eof(mbuff TSRMLS_CC))
@@ -793,6 +836,11 @@ SAPI_API SAPI_POST_HANDLER_FUNC(rfc1867_
 
 		zend_llist_clean(&header);
 
+		if (ZEND_HAS_OOM()) {
+			/* A previous body part has reached the memory limit: stop here */
+			goto fileupload_done;
+		}
+
 		if (!multipart_buffer_headers(mbuff, &header TSRMLS_CC)) {
 			goto fileupload_done;
 		}
@@ -801,6 +849,11 @@ SAPI_API SAPI_POST_HANDLER_FUNC(rfc1867_
 			char *pair = NULL;
 			int end = 0;
 
+			if (--body_parts_cnt < 0) {
+				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Multipart body parts limit exceeded %ld. To increase the limit change max_multipart_body_parts in php.ini.", body_parts_limit);
+				goto fileupload_done;
+			}
+
 			while (isspace(*cd)) {
 				++cd;
 			}
@@ -856,6 +909,17 @@ SAPI_API SAPI_POST_HANDLER_FUNC(rfc1867_
 				char *value = multipart_buffer_read_body(mbuff, &value_len TSRMLS_CC);
 				unsigned int new_val_len; /* Dummy variable */
 
+				if (ZEND_HAS_OOM()) {
+					if (value) {
+						efree(value);
+					}
+					efree(param);
+					if (filename) {
+						efree(filename);
+					}
+					goto fileupload_done;
+				}
+
 				if (!value) {
 					value = estrdup("");
 					value_len = 0;
@@ -1287,6 +1351,9 @@ SAPI_API SAPI_POST_HANDLER_FUNC(rfc1867_
 	}
 
 fileupload_done:
+	if (SG(post_max_size) > 0 && SG(read_post_bytes) > SG(post_max_size)) {
+		sapi_module.sapi_error(E_WARNING, "Actual POST length does not match Content-Length, and exceeds %ld bytes", SG(post_max_size));
+	}
 	if (php_rfc1867_callback != NULL) {
 		multipart_event_end event_end;
 
