$NetBSD: patch-common_ldb__match.c,v 1.2 2023/04/01 08:47:37 taca Exp $

Fix building.

--- common/ldb_match.c.orig	2023-03-29 13:43:36.387152000 +0000
+++ common/ldb_match.c
@@ -33,6 +33,9 @@
  */
 
 #include "ldb_private.h"
+#ifdef HAVE_BSD_STRTOLL
+#undef strtoull
+#endif
 #include "dlinklist.h"
 #include "ldb_handlers.h"
 
