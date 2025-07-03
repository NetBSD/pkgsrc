$NetBSD: patch-mDNSShared_PlatformCommon.c,v 1.1 2025/07/03 10:10:34 jperkin Exp $

Add fcntl.h for fcntl().

--- mDNSShared/PlatformCommon.c.orig	2025-07-03 10:08:38.986077210 +0000
+++ mDNSShared/PlatformCommon.c
@@ -33,6 +33,7 @@
 #include <sys/time.h>           // Needed for #include <sys/time.h>().
 #include <assert.h>
 #include <limits.h>
+#include <fcntl.h>
 
 
 #include "mDNSEmbeddedAPI.h"    // Defines the interface provided to the client layer above
