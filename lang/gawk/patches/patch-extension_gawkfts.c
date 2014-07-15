$NetBSD: patch-extension_gawkfts.c,v 1.1 2014/07/15 14:58:08 ryoon Exp $

--- extension/gawkfts.c.orig	2013-05-02 19:51:30.000000000 +0000
+++ extension/gawkfts.c
@@ -71,6 +71,17 @@ static char sccsid[] = "@(#)fts.c	8.6 (B
 #endif
 */
 
+/*
+ * SCO OpenServer 5.0.7/3.2 has no MAXPATHLEN, but it has PATH_MAX (256).
+ * in limits.h. PATH_MAX is defined alternatively under non-OpenServer OS,
+ * and it is used in dirname.c of bmake.
+ */
+#if !defined(MAXPATHLEN)
+#if defined(_SCO_DS)
+#define MAXPATHLEN	1024
+#endif
+#endif
+
 #ifndef MAX
 static int MAX(int x, int y)
 {
