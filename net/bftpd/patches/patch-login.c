$NetBSD: patch-login.c,v 1.1 2026/07/05 13:36:22 drixter Exp $

Patch suggested by upstream to properly build on Darwin/Apple

--- login.c.orig	2026-07-05 13:28:15.702728596 +0000
+++ login.c
@@ -151,7 +151,7 @@ void bftpd_logwtmp(char type)
         Will use timeval structure to get time instead.
         time(&(ut.ut_time));
         */
-#if !defined(__minix) && !defined(__NetBSD__)
+#if !defined(__minix) && !defined(__NetBSD__) && !defined(__APPLE__)
         gettimeofday(&tv, NULL);
         ut.ut_tv.tv_sec = tv.tv_sec;
         ut.ut_tv.tv_usec = tv.tv_usec;
