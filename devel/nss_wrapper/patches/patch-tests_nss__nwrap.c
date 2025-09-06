$NetBSD: patch-tests_nss__nwrap.c,v 1.1 2025/09/06 18:27:52 riastradh Exp $

Add NetBSD support.

--- tests/nss_nwrap.c.orig	2023-07-28 07:24:34.000000000 +0000
+++ tests/nss_nwrap.c
@@ -28,6 +28,16 @@ typedef nss_status_t NSS_STATUS;
 # define NSS_STATUS_NOTFOUND    NSS_NOTFOUND
 # define NSS_STATUS_UNAVAIL     NSS_UNAVAIL
 # define NSS_STATUS_TRYAGAIN    NSS_TRYAGAIN
+#elif defined(HAVE_NSSWITCH_H)
+/* NetBSD */
+#include <nsswitch.h>
+
+typedef int NSS_STATUS;
+
+# define NSS_STATUS_SUCCESS     NS_SUCCESS
+# define NSS_STATUS_NOTFOUND    NS_NOTFOUND
+# define NSS_STATUS_UNAVAIL     NS_UNAVAIL
+# define NSS_STATUS_TRYAGAIN    NS_TRYAGAIN
 #else
 # error "No nsswitch support detected"
 #endif
