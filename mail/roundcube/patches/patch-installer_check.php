$NetBSD: patch-installer_check.php,v 1.1 2013/09/13 11:13:49 taca Exp $

Roundcube dosen't use php-exif.

--- installer/check.php.orig	2013-09-06 12:20:52.000000000 +0000
+++ installer/check.php
@@ -24,7 +24,6 @@ $optional_php_exts = array(
     'OpenSSL'   => 'openssl',
     'Mcrypt'    => 'mcrypt',
     'Intl'      => 'intl',
-    'Exif'      => 'exif',
 );
 
 $required_libs = array(
