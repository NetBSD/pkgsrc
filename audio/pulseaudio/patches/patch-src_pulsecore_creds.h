$NetBSD: patch-src_pulsecore_creds.h,v 1.3 2024/01/30 13:54:33 ryoon Exp $

* Disable ucred for NetBSD and macOS.

--- src/pulsecore/creds.h.orig	2024-01-12 17:22:09.000000000 +0000
+++ src/pulsecore/creds.h
@@ -34,7 +34,7 @@
 typedef struct pa_creds pa_creds;
 typedef struct pa_cmsg_ancil_data pa_cmsg_ancil_data;
 
-#if (defined(SCM_CREDENTIALS) || defined(SCM_CREDS)) && !defined(OS_IS_DARWIN)
+#if (defined(SCM_CREDENTIALS) || defined(SCM_CREDS)) && !defined(OS_IS_DARWIN) && !defined(__NetBSD__)
 
 #define HAVE_CREDS 1
 
