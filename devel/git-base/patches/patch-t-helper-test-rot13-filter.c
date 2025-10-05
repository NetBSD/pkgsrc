$NetBSD: patch-t-helper-test-rot13-filter.c,v 1.1 2025/10/05 18:09:33 js Exp $

--- t/helper/test-rot13-filter.c.orig	2025-08-18 00:35:38.000000000 +0000
+++ t/helper/test-rot13-filter.c
@@ -44,6 +44,9 @@
 
 static FILE *logfile;
 static int always_delay, has_clean_cap, has_smudge_cap;
+#ifdef __QNX__
+# define delay git_delay
+#endif
 static struct strmap delay = STRMAP_INIT;
 
 static inline const char *str_or_null(const char *str)
