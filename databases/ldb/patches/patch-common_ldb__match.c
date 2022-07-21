$NetBSD: patch-common_ldb__match.c,v 1.1 2022/07/21 08:56:47 adam Exp $

Fix building.

--- common/ldb_match.c.orig	2022-06-14 20:00:35.000000000 +0000
+++ common/ldb_match.c
@@ -33,6 +33,9 @@
  */
 
 #include "ldb_private.h"
+#ifdef HAVE_BSD_STRTOLL
+#undef strtoull
+#endif
 #include "dlinklist.h"
 
 /*
