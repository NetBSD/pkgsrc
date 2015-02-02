$NetBSD: patch-src_iperf__api.h,v 1.1 2015/02/02 12:25:20 he Exp $

Include <sys/time.h> for struct timeval definition.

--- src/iperf_api.h.orig	2015-01-09 17:44:11.000000000 +0000
+++ src/iperf_api.h
@@ -27,6 +27,7 @@
 #ifndef        __IPERF_API_H
 #define        __IPERF_API_H
 
+#include <sys/time.h>
 #include <setjmp.h>
 
 struct iperf_test;
