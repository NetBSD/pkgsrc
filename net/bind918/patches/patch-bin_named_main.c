$NetBSD: patch-bin_named_main.c,v 1.1 2022/12/11 01:57:55 sekiya Exp $

* Based on NetBSD, add support for blocklist(blacklist).

--- bin/named/main.c.orig	2022-11-08 07:17:42.008258118 +0900
+++ bin/named/main.c	2022-12-10 10:08:58.013997862 +0900
@@ -98,6 +98,10 @@
 #ifdef HAVE_LIBNGHTTP2
 #include <nghttp2/nghttp2.h>
 #endif
+#if defined(HAVE_BLACKLIST_H) || defined(HAVE_BLOCKLIST_H)
+#include <ns/pfilter.h>
+#endif
+
 /*
  * Include header files for database drivers here.
  */
@@ -1530,6 +1534,10 @@
 
 	parse_command_line(argc, argv);
 
+#if defined(HAVE_BLACKLIST_H) || defined(HAVE_BLOCKLIST_H)
+	pfilter_enable();
+#endif
+
 #ifdef ENABLE_AFL
 	if (named_g_fuzz_type != isc_fuzz_none) {
 		named_fuzz_setup();
