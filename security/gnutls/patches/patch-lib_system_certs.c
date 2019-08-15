$NetBSD: patch-lib_system_certs.c,v 1.1 2019/08/15 15:46:15 sevan Exp $

Tiger has AvailabilityMacros.h instead of Availability.h
https://trac.macports.org/ticket/53975

--- lib/system/certs.c.orig	2019-07-02 22:04:46.382727993 +0000
+++ lib/system/certs.c
@@ -47,7 +47,13 @@
 #ifdef __APPLE__
 # include <CoreFoundation/CoreFoundation.h>
 # include <Security/Security.h>
+#ifndef __MAC_OS_X_VERSION_MIN_REQUIRED
+#if __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ >= 1050
 # include <Availability.h>
+#else
+# include <AvailabilityMacros.h>
+#endif
+#endif
 #endif
 
 /* System specific function wrappers for certificate stores.
