$NetBSD: patch-localoptions.h,v 1.1 2025/12/22 08:41:05 adam Exp $

Darwin and NetBSD do not have setresgid().

--- localoptions.h.orig	2025-12-22 08:27:44.271032869 +0000
+++ localoptions.h
@@ -0,0 +1,4 @@
+#if defined(__APPLE__) || defined(__NetBSD__)
+#define DROPBEAR_SVR_LOCALSTREAMFWD 0
+#define DROPBEAR_SVR_DROP_PRIVS 0
+#endif
