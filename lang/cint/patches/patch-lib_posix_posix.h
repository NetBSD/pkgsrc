$NetBSD: patch-lib_posix_posix.h,v 1.1 2016/09/28 10:00:27 kamil Exp $

Add support for NetBSD

--- lib/posix/posix.h.orig	2006-11-28 15:08:01.000000000 +0000
+++ lib/posix/posix.h
@@ -283,7 +283,7 @@ extern int setpgrp(pid_t _pid,pid_t _pgr
 #endif
 #elif defined(G__SUN) || defined(__sun)
 extern long setpgrp(void);
-#elif defined(G__FBSD)||defined(__FreeBSD__)||defined(G__OBSD)||defined(__OpenBSD__)||((defined(G__alpha)||defined(__alpha))&&defined(G__GNUC))||((defined(G__alpha)||defined(__alpha))&&defined(G__GNUC))
+#elif defined(G__FBSD)||defined(__FreeBSD__)||defined(G__NBSD)||defined(__NetBSD__)||defined(G__OBSD)||defined(__OpenBSD__)||((defined(G__alpha)||defined(__alpha))&&defined(G__GNUC))||((defined(G__alpha)||defined(__alpha))&&defined(G__GNUC))
 extern int setpgrp(pid_t _pid, pid_t _pgrp);
 #elif defined(G__KCC) || defined(__KCC)
 extern pid_t setpgrp(void);
