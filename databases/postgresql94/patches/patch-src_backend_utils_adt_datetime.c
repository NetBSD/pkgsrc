$NetBSD: patch-src_backend_utils_adt_datetime.c,v 1.1 2015/01/23 15:06:01 joerg Exp $

--- src/backend/utils/adt/datetime.c.orig	2014-12-16 01:07:34.000000000 +0000
+++ src/backend/utils/adt/datetime.c
@@ -31,6 +31,9 @@
 #include "utils/memutils.h"
 #include "utils/tzparser.h"
 
+#if defined(__NetBSD__)
+#define strtoi pg_strtoi
+#endif
 
 static int DecodeNumber(int flen, char *field, bool haveTextMonth,
 			 int fmask, int *tmask,
