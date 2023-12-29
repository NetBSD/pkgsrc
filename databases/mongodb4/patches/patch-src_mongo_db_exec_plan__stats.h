$NetBSD: patch-src_mongo_db_exec_plan__stats.h,v 1.1 2023/12/29 18:24:40 adam Exp $

Add missing include.

--- src/mongo/db/exec/plan_stats.h.orig	2023-08-27 11:41:19.643519257 +0000
+++ src/mongo/db/exec/plan_stats.h
@@ -31,6 +31,7 @@
 
 #include <cstdint>
 #include <cstdlib>
+#include <optional>
 #include <string>
 #include <vector>
 
