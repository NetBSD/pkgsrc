$NetBSD: patch-installer_check.php,v 1.2 2015/02/16 15:33:32 adam Exp $

Roundcube dosen't use php-exif.

--- installer/check.php.orig	2015-02-08 13:48:55.000000000 +0000
+++ installer/check.php
@@ -24,7 +24,6 @@ $optional_php_exts = array(
     'OpenSSL'   => 'openssl',
     'Mcrypt'    => 'mcrypt',
     'Intl'      => 'intl',
-    'Exif'      => 'exif',
     'LDAP'      => 'ldap',
 );
 
