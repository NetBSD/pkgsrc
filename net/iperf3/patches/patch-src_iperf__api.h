$NetBSD: patch-src_iperf__api.h,v 1.3 2025/05/21 22:14:00 wiz Exp $

Add missing header for va_list etc.

--- src/iperf_api.h.orig	2025-05-21 22:13:01.690766581 +0000
+++ src/iperf_api.h
@@ -30,6 +30,7 @@
 #include <sys/socket.h>
 #include <sys/time.h>
 #include <setjmp.h>
+#include <stdarg.h>
 #include <stdio.h>
 #include <stdint.h>
 #ifdef __cplusplus
