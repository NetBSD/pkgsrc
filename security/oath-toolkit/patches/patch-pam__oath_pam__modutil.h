$NetBSD: patch-pam__oath_pam__modutil.h,v 1.1 2022/08/22 07:42:52 sborrill Exp $

Use local fragment of libpam, from FreeBSD

--- pam_oath/pam_modutil.h.orig	2022-01-31 11:03:40 UTC
+++ pam_oath/pam_modutil.h
@@ -0,0 +1,17 @@
+#ifndef PAM_MODUTIL_H
+#define PAM_MODUTIL_H
+
+#ifdef HAVE_SECURITY_PAM_MODUTIL_H
+#include <security/pam_modutil.h>
+#else
+
+#ifdef HAVE_SECURITY_PAM_MODULES_H
+#include <security/pam_modules.h>
+#endif
+
+#include <pwd.h>
+
+struct passwd *pam_modutil_getpwnam(pam_handle_t *pamh, const char *user);
+
+#endif
+#endif
