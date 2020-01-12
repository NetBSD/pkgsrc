$NetBSD: patch-tests_qsdata__test.c,v 1.1 2020/01/12 23:03:28 joerg Exp $

Patch the right function on NetBSD, symbol renaming doesn't agree with
the manual definition.

--- tests/qsdata_test.c.orig	2020-01-11 21:16:44.405991522 +0000
+++ tests/qsdata_test.c
@@ -53,6 +53,8 @@ time(time_t *t __attribute__ ((unused)))
 int
 #ifdef __DARWIN_ONLY_UNIX_CONFORMANCE
 gettimeofday(struct timeval *tv, void *tz)
+#elif defined(__NetBSD__)
+__gettimeofday50(struct timeval * __restrict tv, struct timezone * __restrict tz)
 #else
 gettimeofday(struct timeval *tv, struct timezone *tz)
 #endif
