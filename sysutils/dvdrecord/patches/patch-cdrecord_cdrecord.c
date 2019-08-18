$NetBSD: patch-cdrecord_cdrecord.c,v 1.1 2019/08/18 07:19:47 maya Exp $

- _POSIX_PRIORITY_SCHEDULING is set to -1 if options is not supported (like on darwin)

--- cdrecord/cdrecord.c.orig	2003-06-12 19:05:46.000000000 +0000
+++ cdrecord/cdrecord.c
@@ -2935,7 +2935,7 @@ EXPORT	void raisepri(int pri)
 
 #else	/* HAVE_SYS_PRIOCNTL_H */
 
-#if defined(_POSIX_PRIORITY_SCHEDULING)
+#if defined(_POSIX_PRIORITY_SCHEDULING) && (_POSIX_PRIORITY_SCHEDULING != (-1))
 /*
  * XXX Ugly but needed because of a typo in /usr/iclude/sched.h on Linux.
  * XXX This should be removed as soon as we are sure that Linux-2.0.29 is gone.
