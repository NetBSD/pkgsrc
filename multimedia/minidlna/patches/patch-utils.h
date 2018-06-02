$NetBSD: patch-utils.h,v 1.1 2018/06/02 12:53:10 jmcneill Exp $

--- utils.h.orig	2018-05-04 23:11:25.000000000 +0000
+++ utils.h
@@ -109,4 +109,10 @@ void	timevalsub(struct timeval *t1, cons
 	    ((tvp)->tv_usec cmp (uvp)->tv_usec) :			\
 	    ((tvp)->tv_sec cmp (uvp)->tv_sec))
 
+/* Timespec manipulations */
+#define	timespeccmp(tvp, uvp, cmp)					\
+	(((tvp)->tv_sec == (uvp)->tv_sec) ?				\
+	    ((tvp)->tv_nsec cmp (uvp)->tv_nsec) :			\
+	    ((tvp)->tv_sec cmp (uvp)->tv_sec))
+
 #endif
