$NetBSD: patch-rpmio_rpmfileutil.c,v 1.1 2014/07/28 15:11:00 jperkin Exp $

SunOS libelf.h defines its own "_" macro which overrides the NLS one that
was already set by system.h, so reload system.h to get it back.

--- rpmio/rpmfileutil.c.orig	2013-06-10 15:55:10.000000000 +0000
+++ rpmio/rpmfileutil.c
@@ -13,6 +13,11 @@
 
 #endif
 
+#ifdef __sun
+#undef H_SYSTEM
+#include "system.h"
+#endif
+
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
