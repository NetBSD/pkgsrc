$NetBSD: patch-sapi_fpm_fpm_fpm__conf.c,v 1.1 2025/02/08 02:59:30 taca Exp $

Set proper default configuration values with PHP version.

--- sapi/fpm/fpm/fpm_conf.c.orig	2024-09-26 17:35:59.000000000 +0000
+++ sapi/fpm/fpm/fpm_conf.c
@@ -1266,7 +1266,7 @@ static int fpm_conf_post_process(int for
 	}
 
 	if (!fpm_global_config.error_log) {
-		fpm_global_config.error_log = strdup("log/php-fpm.log");
+		fpm_global_config.error_log = strdup("log/php-fpm@PHP_VER@.log");
 	}
 
 #ifdef HAVE_SYSTEMD
