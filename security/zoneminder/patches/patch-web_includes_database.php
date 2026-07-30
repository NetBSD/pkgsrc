$NetBSD: patch-web_includes_database.php,v 1.1 2026/07/30 12:36:00 gdt Exp $

In order to function in the presence of the latest p5-DBD-msyql --
which refuse to work with MariaDB, we need to have the user patch the
ZM_DB_TYPE to MariaDB so that the DBD::MariaDB is used.  However, in
the land of PHP, there is only php-pdo_mysql, which does both.  Thus,
point MariaDB-using systems at it.

https://github.com/ZoneMinder/zoneminder/issues/5008

--- web/includes/database.php.orig	2026-05-28 08:42:49.000000000 -0400
+++ web/includes/database.php	2026-07-28 18:39:21.597037296 -0400
@@ -31,6 +31,9 @@
   global $dbConn;
 
   $dsn = ZM_DB_TYPE;
+  if ( $dsn = 'MariaDB' ) {
+    $dsn = 'mysql';
+  }
   if ( ZM_DB_HOST ) {
     if ( strpos(ZM_DB_HOST, ':') ) {
       // Host variable may carry a port or socket.
