$NetBSD: patch-libs_aaf_utils.c,v 1.2 2025/01/31 22:01:23 wiz Exp $

Fix build on NetBSD.
https://tracker.ardour.org/view.php?id=9886

--- libs/aaf/utils.c.orig	2025-01-31 16:58:13.463705776 +0000
+++ libs/aaf/utils.c
@@ -32,7 +32,7 @@
 #include <arpa/inet.h>
 #include <mntent.h>
 #include <unistd.h> /* access() */
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__NetBSD__)
 #include <sys/syslimits.h>
 #include <unistd.h> /* access() */
 #elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
