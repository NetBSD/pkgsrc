$NetBSD: patch-protocols_twitter_twitter_lib.c,v 1.1 2025/10/08 09:16:40 mrg Exp $

Don't define _XOPEN_SOURCE and try to use strcasestr().


--- protocols/twitter/twitter_lib.c.orig	2019-02-07 11:53:38.000000000 -0800
+++ protocols/twitter/twitter_lib.c	2025-10-08 02:09:06.139397088 -0700
@@ -23,7 +23,7 @@
 ****************************************************************************/
 
 /* For strptime(): */
-#if (__sun)
+#if (__sun) || defined(__NetBSD__)
 #else
 #define _XOPEN_SOURCE
 #endif
