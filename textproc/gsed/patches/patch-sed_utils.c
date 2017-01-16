$NetBSD: patch-sed_utils.c,v 1.2 2017/01/16 11:45:14 wiz Exp $

--- sed/utils.c.orig	2016-12-11 19:37:01.000000000 +0000
+++ sed/utils.c
@@ -31,6 +31,16 @@
 #include "utils.h"
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
