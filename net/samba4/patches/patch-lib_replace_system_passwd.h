$NetBSD: patch-lib_replace_system_passwd.h,v 1.1 2020/07/06 14:38:06 adam Exp $

Fix building.
https://bugzilla.samba.org/show_bug.cgi?id=14415

--- lib/replace/system/passwd.h.orig	2020-07-06 10:27:14.000000000 +0000
+++ lib/replace/system/passwd.h
@@ -89,4 +89,8 @@
 #define ULTRIX_AUTH 1
 #endif
 
+#ifndef NSS_BUFLEN_PASSWD
+#define NSS_BUFLEN_PASSWD 1024
+#endif
+
 #endif
