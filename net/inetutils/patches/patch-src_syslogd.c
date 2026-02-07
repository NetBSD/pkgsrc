$NetBSD: patch-src_syslogd.c,v 1.2 2026/02/07 09:53:47 vins Exp $

This is only relevant to glibc.

--- src/syslogd.c.orig	2026-02-03 17:15:08.433185757 +0000
+++ src/syslogd.c
@@ -120,7 +120,7 @@
  * the definition LOG_USER = (1 << 3).  Avoid this
  * harmful mistake.
  */
-#ifdef LOG_MAKEPRI
+#if defined (LOG_MAKEPRI) && defined(__GLIBC__)
 # if LOG_MAKEPRI (1, 0) > LOG_PRIMASK
 #  warning Discarding faulty LOG_MAKEPRI defined in system header file.
 #  undef LOG_MAKEPRI
