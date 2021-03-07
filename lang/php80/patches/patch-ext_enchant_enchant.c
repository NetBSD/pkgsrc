$NetBSD: patch-ext_enchant_enchant.c,v 1.1 2021/03/07 13:41:36 taca Exp $

Fix build on pkgsrc environment.

--- ext/enchant/enchant.c.orig	2021-03-02 16:37:06.000000000 +0000
+++ ext/enchant/enchant.c
@@ -24,7 +24,7 @@
 #include "ext/standard/info.h"
 #include "Zend/zend_interfaces.h"
 #include "Zend/zend_exceptions.h"
-#include "../spl/spl_exceptions.h"
+#include "spl/spl_exceptions.h"
 #include <enchant.h>
 #include "php_enchant.h"
 #include "enchant_arginfo.h"
