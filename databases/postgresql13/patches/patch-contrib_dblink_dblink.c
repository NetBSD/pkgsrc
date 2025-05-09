$NetBSD: patch-contrib_dblink_dblink.c,v 1.2 2025/05/09 13:46:30 adam Exp $

--- contrib/dblink/dblink.c.orig	2025-05-05 20:34:49.000000000 +0000
+++ contrib/dblink/dblink.c
@@ -56,7 +56,7 @@
 #include "pgstat.h"
 #include "utils/acl.h"
 #include "utils/builtins.h"
-#include "utils/fmgroids.h"
+#include "postgresql/server/utils/fmgroids.h"
 #include "utils/guc.h"
 #include "utils/lsyscache.h"
 #include "utils/memutils.h"
