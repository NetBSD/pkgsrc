$NetBSD: patch-config_os_macosx_pThreadUtilities.h,v 1.2 2015/01/14 12:10:13 jperkin Exp $

Fix build on Mac OS X.  "1070" isn't necessarily the correct version to test
against, but at least this fixes 1068.

--- config/os/macosx/pThreadUtilities.h.orig	2008-05-29 12:26:05.000000000 +0000
+++ config/os/macosx/pThreadUtilities.h
@@ -66,7 +66,11 @@
 #define __PTHREADUTILITIES_H__
 
 #import "pthread.h"
+#if __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ < 1070
 #import <CoreServices/../Frameworks/CarbonCore.framework/Headers/MacTypes.h>
+#else
+#import <MacTypes.h>
+#endif
 
 #define THREAD_SET_PRIORITY			0
 #define THREAD_SCHEDULED_PRIORITY		1
