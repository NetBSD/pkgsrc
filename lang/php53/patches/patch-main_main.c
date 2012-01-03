$NetBSD: patch-main_main.c,v 1.1 2012/01/03 16:23:14 taca Exp $

* Fix for http://www.ocert.org/advisories/ocert-2011-003.html
  from r321038 from PHP's repository.

--- main/main.c.orig	2012-01-03 02:28:53.000000000 +0000
+++ main/main.c
@@ -504,6 +504,7 @@ PHP_INI_BEGIN()
 	STD_PHP_INI_ENTRY("post_max_size",			"8M",		PHP_INI_SYSTEM|PHP_INI_PERDIR,		OnUpdateLong,			post_max_size,			sapi_globals_struct,sapi_globals)
 	STD_PHP_INI_ENTRY("upload_tmp_dir",			NULL,		PHP_INI_SYSTEM,		OnUpdateStringUnempty,	upload_tmp_dir,			php_core_globals,	core_globals)
 	STD_PHP_INI_ENTRY("max_input_nesting_level", "64",		PHP_INI_SYSTEM|PHP_INI_PERDIR,		OnUpdateLongGEZero,	max_input_nesting_level,			php_core_globals,	core_globals)
+	STD_PHP_INI_ENTRY("max_input_vars",			"1000",		PHP_INI_SYSTEM|PHP_INI_PERDIR,		OnUpdateLongGEZero,	max_input_vars,						php_core_globals,	core_globals)
 
 	STD_PHP_INI_ENTRY("user_dir",				NULL,		PHP_INI_SYSTEM,		OnUpdateString,			user_dir,				php_core_globals,	core_globals)
 	STD_PHP_INI_ENTRY("variables_order",		"EGPCS",	PHP_INI_SYSTEM|PHP_INI_PERDIR,		OnUpdateStringUnempty,	variables_order,		php_core_globals,	core_globals)
