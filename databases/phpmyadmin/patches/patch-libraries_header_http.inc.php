$NetBSD: patch-libraries_header_http.inc.php,v 1.1 2012/05/06 09:01:10 tron Exp $

Restore compatibility with Safari:

http://sourceforge.net/tracker/?func=detail&aid=3523499&group_id=23067&atid=377408

--- libraries/header_http.inc.php.orig	2012-05-03 17:37:53.000000000 +0100
+++ libraries/header_http.inc.php	2012-05-06 09:54:24.000000000 +0100
@@ -23,7 +23,7 @@
 if (!$GLOBALS['cfg']['AllowThirdPartyFraming']) {
     header('X-Frame-Options: SAMEORIGIN');
     header('X-Content-Security-Policy: allow \'self\'; options inline-script eval-script; frame-ancestors \'self\'; img-src \'self\' data:; script-src \'self\' http://www.phpmyadmin.net');
-    header('X-WebKit-CSP: default-src \'self\' \'unsafe-inline\'; img-src \'self\' data:; script-src \'self\' \'unsafe-inline\' \'unsafe-eval\' http://www.phpmyadmin.net');
+/*    header('X-WebKit-CSP: default-src \'self\' \'unsafe-inline\'; img-src \'self\' data:; script-src \'self\' \'unsafe-inline\' \'unsafe-eval\' http://www.phpmyadmin.net');*/
 }
 PMA_no_cache_header();
 if (!defined('IS_TRANSFORMATION_WRAPPER')) {
