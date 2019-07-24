$NetBSD: patch-portable.h,v 1.1 2019/07/24 11:15:41 maya Exp $

Avoid re-defining timespecsub on netbsd, that already has it.

--- portable.h.orig	2019-04-10 23:55:43.000000000 +0000
+++ portable.h
@@ -151,6 +151,7 @@
             ((tsp)->tv_nsec cmp (usp)->tv_nsec) :                       \
             ((tsp)->tv_sec cmp (usp)->tv_sec))
 
+#ifndef timespecsub
 #define timespecsub(tsp, usp, vsp)                                      \
         do {                                                            \
                 (vsp)->tv_sec = (tsp)->tv_sec - (usp)->tv_sec;          \
@@ -160,6 +161,7 @@
                         (vsp)->tv_nsec += 1000000000L;                  \
                 }                                                       \
         } while (0)
+#endif
 #endif /* !__OpenBSD__ */
 
 #if !defined(HAVE_ST_MTIM) && !defined(HAVE_ST_MTIMESPEC)
