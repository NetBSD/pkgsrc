$NetBSD: patch-src_pulsecore_creds.h,v 1.1 2021/07/30 12:21:06 ryoon Exp $

* Disable ucred for NetBSD.

--- src/pulsecore/creds.h.orig	2021-07-27 20:02:27.821869100 +0000
+++ src/pulsecore/creds.h
@@ -34,7 +34,7 @@
 typedef struct pa_creds pa_creds;
 typedef struct pa_cmsg_ancil_data pa_cmsg_ancil_data;
 
-#if defined(SCM_CREDENTIALS) || defined(SCM_CREDS)
+#if (defined(SCM_CREDENTIALS) || defined(SCM_CREDS)) && !defined(__NetBSD__)
 
 #define HAVE_CREDS 1
 
