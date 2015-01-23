$NetBSD: patch-src_interfaces_ecpg_pgtypeslib_interval.c,v 1.1 2015/01/23 15:06:01 joerg Exp $

--- src/interfaces/ecpg/pgtypeslib/interval.c.orig	2014-07-21 19:14:13.000000000 +0000
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
 strtoi(const char *nptr, char **endptr, int base)
