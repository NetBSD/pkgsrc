$NetBSD: patch-library_Icinga_Application_webrouter.php,v 1.1 2021/01/19 08:12:06 wiz Exp $

Replace convoluted path computation by something much simpler that 
actually works reliably.

--- library/Icinga/Application/webrouter.php.orig	2018-11-21 09:19:00.000000000 +0100
+++ library/Icinga/Application/webrouter.php	2019-03-21 17:00:08.000000000 +0100
@@ -9,12 +9,6 @@
 
 error_reporting(E_ALL | E_STRICT);
 
-if (isset($_SERVER['REQUEST_URI'])) {
-    $ruri = $_SERVER['REQUEST_URI'];
-} else {
-    return false;
-}
-
 // Workaround, PHPs internal Webserver seems to mess up SCRIPT_FILENAME
 // as it prefixes it's absolute path with DOCUMENT_ROOT
 if (preg_match('/^PHP .* Development Server/', $_SERVER['SERVER_SOFTWARE'])) {
@@ -28,18 +22,12 @@
 $baseDir = $_SERVER['DOCUMENT_ROOT'];
 $baseDir = dirname($_SERVER['SCRIPT_FILENAME']);
 
-// Fix aliases
-$remove = str_replace('\\', '/', dirname($_SERVER['PHP_SELF']));
-if (substr($ruri, 0, strlen($remove)) !== $remove) {
-    return false;
-}
-$ruri = ltrim(substr($ruri, strlen($remove)), '/');
-
-if (strpos($ruri, '?') === false) {
-    $params = '';
-    $path = $ruri;
+if (!isset($_SERVER['PATH_INFO'])) {
+    $path = '';
+} elseif ($_SERVER['PATH_INFO'] === '') {
+    $path = '';
 } else {
-    list($path, $params) = preg_split('/\?/', $ruri, 2);
+    $path = ltrim($_SERVER['PATH_INFO'], '/'); // remove leading slash
 }
 
 $special = array(
