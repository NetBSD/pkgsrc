$NetBSD: patch-lib_common.php,v 1.1 2022/04/16 03:11:28 khorben Exp $

--- lib/common.php.orig	2012-10-01 06:54:14.000000000 +0000
+++ lib/common.php
@@ -296,7 +296,9 @@ if ($app['language'] == 'auto') {
  * Strip slashes from GET, POST, and COOKIE variables if this
  * PHP install is configured to automatically addslashes()
  */
-if (@get_magic_quotes_gpc() && (! isset($slashes_stripped) || ! $slashes_stripped)) {
+if (@version_compare(phpversion(), '5.4.0', '<') &&
+    @get_magic_quotes_gpc() &&
+    (!isset($slashes_stripped) || !$slashes_stripped)) {
 	array_stripslashes($_REQUEST);
 	array_stripslashes($_GET);
 	array_stripslashes($_POST);
