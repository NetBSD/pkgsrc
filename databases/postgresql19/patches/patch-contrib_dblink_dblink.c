$NetBSD: patch-contrib_dblink_dblink.c,v 1.1 2026/11/24 19:22:51 adam Exp $

--- contrib/dblink/dblink.c.orig	2026-11-16 20:02:58.000000000 +0000
+++ contrib/dblink/dblink.c
@@ -57,7 +57,7 @@
 #include "parser/scansup.h"
 #include "utils/acl.h"
 #include "utils/builtins.h"
-#include "utils/fmgroids.h"
+#include "postgresql/server/utils/fmgroids.h"
 #include "utils/guc.h"
 #include "utils/hsearch.h"
 #include "utils/lsyscache.h"
