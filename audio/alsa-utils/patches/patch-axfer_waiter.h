$NetBSD: patch-axfer_waiter.h,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- axfer/waiter.h.orig	2023-09-01 15:36:26.000000000 +0000
+++ axfer/waiter.h
@@ -9,6 +9,7 @@
 #ifndef __ALSA_UTILS_AXFER_WAITER__H_
 #define __ALSA_UTILS_AXFER_WAITER__H_
 
+#include <alsa/global.h>
 #include <poll.h>
 
 enum waiter_type {
