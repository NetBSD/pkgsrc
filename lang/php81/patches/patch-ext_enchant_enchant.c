$NetBSD: patch-ext_enchant_enchant.c,v 1.1 2021/11/27 07:24:43 taca Exp $

Fix build on pkgsrc environment.

--- ext/enchant/enchant.c.orig	2021-10-27 00:20:44.000000000 +0000
+++ ext/enchant/enchant.c
@@ -23,7 +23,7 @@
 #include "php_ini.h"
 #include "ext/standard/info.h"
 #include "Zend/zend_exceptions.h"
-#include "../spl/spl_exceptions.h"
+#include "spl/spl_exceptions.h"
 #include <enchant.h>
 #include "php_enchant.h"
 #include "enchant_arginfo.h"
