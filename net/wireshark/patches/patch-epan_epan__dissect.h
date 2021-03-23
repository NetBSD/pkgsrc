$NetBSD: patch-epan_epan__dissect.h,v 1.1 2021/03/23 10:48:42 adam Exp $

Fix building with Glib 2.68.

--- epan/epan_dissect.h.orig	2021-03-23 09:24:04.000000000 +0000
+++ epan/epan_dissect.h
@@ -10,11 +10,12 @@
 #ifndef EPAN_DISSECT_H
 #define EPAN_DISSECT_H
 
+#include "epan.h"
+
 #ifdef __cplusplus
 extern "C" {
 #endif /* __cplusplus */
 
-#include "epan.h"
 #include "tvbuff.h"
 #include "proto.h"
 #include "packet_info.h"
