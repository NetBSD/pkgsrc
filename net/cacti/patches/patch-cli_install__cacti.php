$NetBSD: patch-cli_install__cacti.php,v 1.1 2019/04/29 16:09:05 hauke Exp $

Make log directory configurable by package variable

--- cli/install_cacti.php.orig	2019-03-30 23:40:22.000000000 +0000
+++ cli/install_cacti.php
@@ -364,7 +364,7 @@ function display_help () {
 	print '  Note: reusing an option_key will replace its value with the last one' . PHP_EOL;
 	print '        specified.' .PHP_EOL . PHP_EOL;
 	print '       --path             - Sets path locations. Example: ' . PHP_EOL;
-	print '                              --path=cactilog:/usr/share/cacti/log/cacti.log' . PHP_EOL;
+	print '                              --path=cactilog:@CACTI_LOGDIR@/cacti.log' . PHP_EOL;
 	print '                              --path=cactilog:c:\cacti\log\cacti.log' . PHP_EOL;
 	print '                            Prefix: path_' . PHP_EOL;
 	print PHP_EOL;
