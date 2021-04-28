$NetBSD: patch-src_include_utils_fe__ports.h,v 1.1 2021/04/28 09:18:55 wiz Exp $

--- src/include/utils/fe_ports.h.orig	2021-04-24 00:38:17.082783710 +0300
+++ src/include/utils/fe_ports.h	2021-04-24 00:38:58.811176898 +0300
@@ -29,6 +29,7 @@
 #endif
 
 #include <stdlib.h>
+#include <stdarg.h>
 #ifndef FE_PORTS
 #define FE_PORTS
 #include "parser/pg_config_manual.h"
