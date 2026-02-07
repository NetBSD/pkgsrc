$NetBSD: patch-include_freetds_thread.h,v 1.2 2026/02/07 18:22:48 adam Exp $

Check _REENTRANT, too.

--- include/freetds/thread.h.orig	2025-03-06 20:38:39.000000000 +0000
+++ include/freetds/thread.h
@@ -24,7 +24,7 @@
 
 #undef TDS_HAVE_MUTEX
 
-#if defined(_THREAD_SAFE) && defined(TDS_HAVE_PTHREAD_MUTEX)
+#if (defined(_REENTRANT) || defined(_THREAD_SAFE)) && defined(TDS_HAVE_PTHREAD_MUTEX)
 
 #include <tds_sysdep_public.h>
 #include <freetds/sysdep_private.h>
