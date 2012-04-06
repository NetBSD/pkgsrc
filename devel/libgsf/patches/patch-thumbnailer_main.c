$NetBSD: patch-thumbnailer_main.c,v 1.1 2012/04/06 10:42:38 taca Exp $

* Fix build problem on the platform without RLIMIT_AS; NetBSD 4.

--- thumbnailer/main.c.orig	2011-12-07 23:05:18.000000000 +0000
+++ thumbnailer/main.c
@@ -258,9 +258,11 @@ set_resource_limits (void)
 	 * time on certain WMFs.  So, we'll put a cap on how much resources it can use.
 	 */
 
+#ifdef RLIMIT_AS
 	limit.rlim_cur = MAX_HELPER_MEMORY;
 	limit.rlim_max = MAX_HELPER_MEMORY;
 	setrlimit (RLIMIT_AS, &limit);
+#endif
 
 	limit.rlim_cur = MAX_HELPER_SECONDS;
 	limit.rlim_max = MAX_HELPER_SECONDS;
