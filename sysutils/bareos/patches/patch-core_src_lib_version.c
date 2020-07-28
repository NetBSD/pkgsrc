$NetBSD: patch-core_src_lib_version.c,v 1.1 2020/07/28 06:36:29 kardel Exp $

	note pkgsrc compile origin

--- core/src/lib/version.c.orig	2020-04-16 08:31:41.000000000 +0000
+++ core/src/lib/version.c
@@ -48,18 +48,18 @@
 #endif
 
 #if !defined BAREOS_BINARY_INFO
-#define BAREOS_BINARY_INFO "self-compiled"
+#define BAREOS_BINARY_INFO "pkgsrc-compiled"
 #endif
 
 #if !defined BAREOS_SERVICES_MESSAGE
 #define BAREOS_SERVICES_MESSAGE                             \
-  "self-compiled binaries are UNSUPPORTED by bareos.com.\n" \
+  "pkgsrc-compiled binaries are UNSUPPORTED by bareos.com.\n" \
   "Get official binaries and vendor support on https://www.bareos.com"
 #endif
 
 #if !defined BAREOS_JOBLOG_MESSAGE
 #define BAREOS_JOBLOG_MESSAGE \
-  "self-compiled: Get official binaries and vendor support on bareos.com"
+  "pkgsrc-compiled: Get official binaries and vendor support on bareos.com"
 #endif
 
 #define BAREOS_COPYRIGHT_MESSAGE_WITH_FSF_AND_PLANETS            \
