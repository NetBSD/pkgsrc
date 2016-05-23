$NetBSD: patch-src_interfaces_ecpg_pgtypeslib_interval.c,v 1.2 2016/05/23 14:27:34 adam Exp $

--- src/interfaces/ecpg/pgtypeslib/interval.c.orig	2016-05-23 12:13:46.000000000 +0000
+++ src/interfaces/ecpg/pgtypeslib/interval.c
@@ -14,6 +14,10 @@
 #include "pgtypes_error.h"
 #include "pgtypes_interval.h"
 
+#if defined(__NetBSD__)
+#define strtoi pg_strtoi
+#endif
+
 /* copy&pasted from .../src/backend/utils/adt/datetime.c */
 static int
 strtoint(const char *nptr, char **endptr, int base)
