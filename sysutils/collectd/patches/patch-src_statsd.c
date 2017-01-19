$NetBSD: patch-src_statsd.c,v 1.1 2017/01/19 17:20:42 he Exp $

Insert workaround for possibly missing nearbyint().
(Could be more specific, but test would be ... complicated.)

--- src/statsd.c.orig	2017-01-19 16:24:15.000000000 +0000
+++ src/statsd.c
@@ -48,6 +48,11 @@
 #define STATSD_DEFAULT_SERVICE "8125"
 #endif
 
+#ifdef __NetBSD__
+/* May not have this, could be more specific... */
+#define nearbyint(v)	rint((v))
+#endif
+
 enum metric_type_e { STATSD_COUNTER, STATSD_TIMER, STATSD_GAUGE, STATSD_SET };
 typedef enum metric_type_e metric_type_t;
 
