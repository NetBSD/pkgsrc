$NetBSD: patch-src_setu_gnunet-service-setu.c,v 1.1 2023/01/31 18:53:46 nikita Exp $

Crudely fix NetBSD's missing log2l.

--- src/setu/gnunet-service-setu.c.orig	2022-03-18 23:02:08.123202128 +0100
+++ src/setu/gnunet-service-setu.c	2022-03-18 23:03:42.434385369 +0100
@@ -38,6 +38,10 @@
 #include "gnunet_setu_service.h"
 #include "setu.h"
 
+#ifdef __NetBSD__
+#define log2l log2
+#endif
+
 #define LOG(kind, ...) GNUNET_log_from (kind, "setu", __VA_ARGS__)
 
 /**
