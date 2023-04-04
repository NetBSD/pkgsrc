$NetBSD: patch-src_hitch.c,v 1.4 2023/04/04 21:51:07 tpaul Exp $

Avoid "sun" conflict.

--- src/hitch.c.orig	2021-11-29 12:09:28.000000000 +0000
+++ src/hitch.c
@@ -124,6 +124,10 @@
 #  define X509_NAME_ENTRY_get_data(entry) ((entry)->value)
 #endif
 
+#ifdef __sun
+#undef sun
+#endif
+
 /* logging.c */
 extern FILE *logfile;
 extern struct stat logf_st;
