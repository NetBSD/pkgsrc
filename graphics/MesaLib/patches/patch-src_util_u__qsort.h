$NetBSD: patch-src_util_u__qsort.h,v 1.1 2025/03/07 06:56:20 wiz Exp $

Fix for POSIX qsort_r on NetBSD.
(FreeBSD before 14 had the qsort_r argument order different than Linux.)

--- src/util/u_qsort.h.orig	2025-03-07 06:52:32.373984663 +0000
+++ src/util/u_qsort.h
@@ -57,7 +57,7 @@ util_qsort_r(void *base, size_t nmemb, s
              void *arg)
 {
 #if HAVE_QSORT_R
-#  if DETECT_OS_APPLE || DETECT_OS_BSD
+#  if DETECT_OS_APPLE || DETECT_OS_BSD && !defined(__NetBSD__)
    /* BSD/macOS qsort_r takes "arg" before the comparison function and it
     * pass the "arg" before the elements.
     */
