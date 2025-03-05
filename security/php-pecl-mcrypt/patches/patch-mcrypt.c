$NetBSD: patch-mcrypt.c,v 1.1 2025/03/05 15:24:18 taca Exp $

Fix build on PHP 8.4 (and maybe later).

--- mcrypt.c.orig	2023-12-19 10:55:02.000000000 +0000
+++ mcrypt.c
@@ -38,7 +38,11 @@
 #include "php_ini.h"
 #include "php_globals.h"
 #include "ext/standard/info.h"
+#if PHP_VERSION_ID < 80400
 #include "ext/standard/php_rand.h"
+#else
+#include "ext/random/php_random.h"
+#endif
 #include "zend_smart_str.h"
 #include "php_mcrypt_filter.h"
 
