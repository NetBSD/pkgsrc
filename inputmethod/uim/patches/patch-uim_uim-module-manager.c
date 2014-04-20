$NetBSD: patch-uim_uim-module-manager.c,v 1.1 2014/04/20 06:40:00 ryoon Exp $

https://github.com/uim/uim/pull/41

--- uim/uim-module-manager.c.orig	2013-06-30 04:26:09.000000000 +0000
+++ uim/uim-module-manager.c
@@ -47,8 +47,8 @@
 #include "uim-internal.h"
 
 #define MODULE_LIST_FILENAME UIM_DATADIR"/modules"
-#define LOADER_SCM_FILENAME  UIM_DATADIR"/loader.scm"
-#define INSTALLED_MODULES_SCM_FILENAME  UIM_DATADIR"/installed-modules.scm"
+#define LOADER_SCM_FILENAME  UIM_CONFDIR"/loader.scm"
+#define INSTALLED_MODULES_SCM_FILENAME  UIM_CONFDIR"/installed-modules.scm"
 
 static char *path;
 
