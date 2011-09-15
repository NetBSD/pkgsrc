$NetBSD: patch-contrib_dblink_dblink.c,v 1.1.1.1 2011/09/15 08:27:39 adam Exp $

--- contrib/dblink/dblink.c.orig	2010-07-06 19:18:54.000000000 +0000
+++ contrib/dblink/dblink.c
@@ -59,7 +59,7 @@
 #include "utils/array.h"
 #include "utils/builtins.h"
 #include "utils/dynahash.h"
-#include "utils/fmgroids.h"
+#include "postgresql/server/utils/fmgroids.h"
 #include "utils/hsearch.h"
 #include "utils/lsyscache.h"
 #include "utils/memutils.h"
