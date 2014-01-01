$NetBSD: patch-os__mac.h,v 1.1 2014/01/01 14:44:59 schmonz Exp $

Avoid conflicting sigaltstack types on OS X 10.9.

--- src/os_mac.h.orig	2013-05-21 21:24:07.000000000 +0000
+++ src/os_mac.h
@@ -16,6 +16,9 @@
 # define OPAQUE_TOOLBOX_STRUCTS 0
 #endif
 
+/* Include MAC_OS_X_VERSION_* macros */
+#include <AvailabilityMacros.h>
+
 /*
  * Macintosh machine-dependent things.
  *
