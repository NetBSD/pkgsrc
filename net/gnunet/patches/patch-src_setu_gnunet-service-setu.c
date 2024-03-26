$NetBSD: patch-src_setu_gnunet-service-setu.c,v 1.3 2024/03/26 20:45:56 nikita Exp $

Crudely fix NetBSD's missing log2l.

log2* (2) is always 1.

diff --git a/src/setu/gnunet-service-setu.c b/src/setu/gnunet-service-setu.c
index f85ddb224..a8572c0e2 100644
--- src/service/setu/gnunet-service-setu.c.orig
+++ src/service/setu/gnunet-service-setu.c
@@ -38,6 +38,10 @@
 #include "gnunet_setu_service.h"
 #include "setu.h"
 
+#ifdef __NetBSD__
+#define log2l log2
+#endif
+
 #define LOG(kind, ...) GNUNET_log_from (kind, "setu", __VA_ARGS__)
 
 /**
@@ -1800,7 +1804,7 @@ full_sync_plausibility_check (struct Operation *op)
                                                                            double)
                                                                         op->
                                                                         remote_set_diff)));
-    long double value = exponent * (log2l (base) / log2l (2));
+    long double value = exponent * (log2l (base) / 1);
     if ((value < security_level_lb) || (value > SECURITY_LEVEL) )
     {
       LOG (GNUNET_ERROR_TYPE_ERROR,
@@ -1824,7 +1828,7 @@ check_max_differential_rounds (struct Operation *op)
 {
   double probability = op->differential_sync_iterations * (log2l (
                                                              PROBABILITY_FOR_NEW_ROUND)
-                                                           / log2l (2));
+                                                           / 1);
   if ((-1 * SECURITY_LEVEL) > probability)
   {
     LOG (GNUNET_ERROR_TYPE_ERROR,
