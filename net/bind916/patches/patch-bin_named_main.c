$NetBSD: patch-bin_named_main.c,v 1.2 2020/12/19 16:41:36 taca Exp $

* Based on NetBSD, add support for blocklist(blacklist).

--- bin/named/main.c.orig	2020-12-07 08:16:53.000000000 +0000
+++ bin/named/main.c
@@ -95,6 +95,10 @@
 #ifdef HAVE_ZLIB
 #include <zlib.h>
 #endif /* ifdef HAVE_ZLIB */
+#if defined(HAVE_BLACKLIST_H) || defined(HAVE_BLOCKLIST_H)
+#include <ns/pfilter.h>
+#endif
+
 /*
  * Include header files for database drivers here.
  */
@@ -1535,6 +1539,10 @@ main(int argc, char *argv[]) {
 
 	parse_command_line(argc, argv);
 
+#if defined(HAVE_BLACKLIST_H) || defined(HAVE_BLOCKLIST_H)
+	pfilter_enable();
+#endif
+
 #ifdef ENABLE_AFL
 	if (named_g_fuzz_type != isc_fuzz_none) {
 		named_fuzz_setup();
