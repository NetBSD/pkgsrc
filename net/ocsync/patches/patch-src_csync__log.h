$NetBSD: patch-src_csync__log.h,v 1.1 2021/01/13 09:40:40 nia Exp $

Fix build with gcc>=5, use c99-compliant identifier.

--- src/csync_log.h.orig	2013-10-18 13:11:09.000000000 +0000
+++ src/csync_log.h
@@ -61,7 +61,7 @@ enum csync_log_priority_e {
 };
 
 #define CSYNC_LOG(priority, ...) \
-  csync_log(ctx, priority, __FUNCTION__, __VA_ARGS__)
+  csync_log(ctx, priority, __func__, __VA_ARGS__)
 
 void csync_log(CSYNC *ctx,
                int verbosity,
