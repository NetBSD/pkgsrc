$NetBSD: patch-libraries_adodb_drivers_adodb-postgres64.inc.php,v 1.1 2023/10/16 13:02:26 hauke Exp $

Unbreak on php-8, from
<https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=263759>

--- libraries/adodb/drivers/adodb-postgres64.inc.php.orig	2020-11-07 06:09:12.000000000 +0000
+++ libraries/adodb/drivers/adodb-postgres64.inc.php
@@ -121,6 +121,11 @@ WHERE relkind in ('r','v') AND (c.relnam
 	{
 	// changes the metaColumnsSQL, adds columns: attnum[6]
 	}
+
+	function __construct()
+	{
+		// non-virtual
+	}
 	
 	function ServerInfo()
 	{
