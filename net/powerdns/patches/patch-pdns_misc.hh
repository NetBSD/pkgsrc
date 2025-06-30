$NetBSD: patch-pdns_misc.hh,v 1.3 2025/06/30 11:00:50 jperkin Exp $

Checking for CLOCK_THREAD_CPUTIME_ID is sufficient, not all systems
define _POSIX_THREAD_CPUTIME.

--- pdns/misc.hh.orig	2025-06-20 13:40:32.920712323 +0000
+++ pdns/misc.hh
@@ -187,7 +187,7 @@ string bitFlip(const string &str);
 void dropPrivs(int uid, int gid);
 void cleanSlashes(string &str);
 
-#if defined(_POSIX_THREAD_CPUTIME) && defined(CLOCK_THREAD_CPUTIME_ID)
+#if defined(CLOCK_THREAD_CPUTIME_ID)
 /** CPUTime measurements */
 class CPUTime
 {
