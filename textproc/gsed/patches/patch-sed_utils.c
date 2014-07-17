$NetBSD: patch-sed_utils.c,v 1.1 2014/07/17 12:24:34 ryoon Exp $

--- sed/utils.c.orig	2012-03-16 09:13:31.000000000 +0000
+++ sed/utils.c
@@ -32,6 +32,16 @@
 #include "pathmax.h"
 #include "fwriting.h"
 
+/*
+ * SCO OpenServer 5.0.7/3.2 has no MAXPATHLEN, but it has PATH_MAX (256).
+ * in limits.h. PATH_MAX is not available under ordinary condition.
+ */
+#if !defined(PATH_MAX)
+#if defined(_SCO_DS)
+#define PATH_MAX	1024
+#endif
+#endif
+
 const char *myname;
 
 /* Store information about files opened with ck_fopen
