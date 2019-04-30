$NetBSD: patch-bin_named_main.c,v 1.1 2019/04/30 03:34:34 taca Exp $

* Add support for blacklistd.

--- bin/named/main.c.orig	2019-04-06 20:09:59.000000000 +0000
+++ bin/named/main.c
@@ -85,6 +85,9 @@
 #ifdef HAVE_ZLIB
 #include <zlib.h>
 #endif
+#ifdef HAVE_BLACKLIST
+#include "pfilter.h"
+#endif
 /*
  * Include header files for database drivers here.
  */
@@ -1399,6 +1402,10 @@ main(int argc, char *argv[]) {
 
 	parse_command_line(argc, argv);
 
+#ifdef HAVE_BLACKLIST
+	pfilter_open();
+#endif
+
 #ifdef ENABLE_AFL
 	if (named_g_fuzz_type != isc_fuzz_none) {
 		named_fuzz_setup();
