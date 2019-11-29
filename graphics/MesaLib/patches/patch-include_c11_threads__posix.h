$NetBSD: patch-include_c11_threads__posix.h,v 1.1 2019/11/29 10:34:13 jperkin Exp $

Use compat version of timespec_get regardless on Darwin.  The
meson configure test completes successfully even with clearly
bogus values.

--- include/c11/threads_posix.h.orig	2019-11-22 00:06:57.000000000 +0000
+++ include/c11/threads_posix.h
@@ -382,7 +382,7 @@ tss_set(tss_t key, void *val)
 
 /*-------------------- 7.25.7 Time functions --------------------*/
 // 7.25.6.1
-#ifndef HAVE_TIMESPEC_GET
+#if !defined(HAVE_TIMESPEC_GET) || defined(__APPLE__)
 static inline int
 timespec_get(struct timespec *ts, int base)
 {
