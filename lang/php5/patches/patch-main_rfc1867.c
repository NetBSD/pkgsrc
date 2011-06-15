$NetBSD: patch-main_rfc1867.c,v 1.1 2011/06/15 14:41:16 taca Exp $

* Update of r312103 of PHP's repository, fix filename-injection vulnerability.

--- main/rfc1867.c.orig	2010-03-18 22:37:25.000000000 +0000
+++ main/rfc1867.c
@@ -1215,7 +1215,7 @@ filedone:
 #endif
 
 			if (!is_anonymous) {
-				if (s && s > filename) {
+				if (s && s >= filename) {
 					safe_php_register_variable(lbuf, s+1, strlen(s+1), NULL, 0 TSRMLS_CC);
 				} else {
 					safe_php_register_variable(lbuf, filename, strlen(filename), NULL, 0 TSRMLS_CC);
@@ -1228,7 +1228,7 @@ filedone:
 			} else {
 				snprintf(lbuf, llen, "%s[name]", param);
 			}
-			if (s && s > filename) {
+			if (s && s >= filename) {
 				register_http_post_files_variable(lbuf, s+1, http_post_files, 0 TSRMLS_CC);
 			} else {
 				register_http_post_files_variable(lbuf, filename, http_post_files, 0 TSRMLS_CC);
