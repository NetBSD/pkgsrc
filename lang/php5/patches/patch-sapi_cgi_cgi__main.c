$NetBSD: patch-sapi_cgi_cgi__main.c,v 1.1.2.2 2012/05/16 12:50:45 tron Exp $

* fix for CVE-2012-1823.

--- sapi/cgi/cgi_main.c.orig	2010-01-03 09:23:27.000000000 +0000
+++ sapi/cgi/cgi_main.c
@@ -1405,7 +1405,7 @@ int main(int argc, char *argv[])
 	}
 #endif
 
-	while ((c = php_getopt(argc, argv, OPTIONS, &php_optarg, &php_optind, 0)) != -1) {
+	while (!cgi && (c = php_getopt(argc, argv, OPTIONS, &php_optarg, &php_optind, 0)) != -1) {
 		switch (c) {
 			case 'c':
 				if (cgi_sapi_module.php_ini_path_override) {
@@ -1659,7 +1659,7 @@ consult the installation file that came 
 #endif /* FASTCGI */
 
 	zend_first_try {
-		while ((c = php_getopt(argc, argv, OPTIONS, &php_optarg, &php_optind, 1)) != -1) {
+		while (!cgi && (c = php_getopt(argc, argv, OPTIONS, &php_optarg, &php_optind, 1)) != -1) {
 			switch (c) {
 #if PHP_FASTCGI
 				case 'T':
