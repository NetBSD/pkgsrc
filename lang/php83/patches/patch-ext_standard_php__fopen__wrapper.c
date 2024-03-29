$NetBSD: patch-ext_standard_php__fopen__wrapper.c,v 1.1 2023/11/30 16:14:50 taca Exp $

Add build-time disable option for dangerous php://filter URL

php://filter URL is a feature documented here:
http://php.net/manual/en/wrappers.php.php

Unfortunately, it allows remote control of include() behavior
beyond what many developpers expected, enabling easy dump of
PHP source files. The administrator may want to disable the
feature for security sake, and this patch makes that possible.

--- ext/standard/php_fopen_wrapper.c.orig	2019-11-19 10:24:58.000000000 +0000
+++ ext/standard/php_fopen_wrapper.c
@@ -338,6 +338,7 @@ php_stream * php_stream_url_wrap_php(php
 				"[%d]: %s", fildes_ori, errno, strerror(errno));
 			return NULL;
 		}
+#ifndef DISABLE_FILTER_URL
 	} else if (!strncasecmp(path, "filter/", 7)) {
 		/* Save time/memory when chain isn't specified */
 		if (strchr(mode, 'r') || strchr(mode, '+')) {
@@ -380,6 +381,7 @@ php_stream * php_stream_url_wrap_php(php
 		}
 
 		return stream;
+#endif /* !DISABLE_FILTER_URL */
 	} else {
 		/* invalid php://thingy */
 		php_error_docref(NULL, E_WARNING, "Invalid php:// URL specified");
