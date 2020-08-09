$NetBSD: patch-bin_named_main.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base including support for blacklistd.

--- bin/named/main.c.orig	2020-06-10 21:01:43.000000000 +0000
+++ bin/named/main.c
@@ -94,6 +94,10 @@
 #ifdef HAVE_ZLIB
 #include <zlib.h>
 #endif /* ifdef HAVE_ZLIB */
+#ifdef HAVE_BLACKLIST
+#include <ns/pfilter.h>
+#endif /* ifdef HAVE_BLACKLIST */
+
 /*
  * Include header files for database drivers here.
  */
@@ -1529,6 +1533,10 @@ main(int argc, char *argv[]) {
 
 	parse_command_line(argc, argv);
 
+#ifdef HAVE_BLACKLIST
+	pfilter_enable();
+#endif
+
 #ifdef ENABLE_AFL
 	if (named_g_fuzz_type != isc_fuzz_none) {
 		named_fuzz_setup();
