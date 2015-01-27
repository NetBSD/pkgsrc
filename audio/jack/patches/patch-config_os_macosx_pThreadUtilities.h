$NetBSD: patch-config_os_macosx_pThreadUtilities.h,v 1.4 2015/01/27 04:37:53 dbj Exp $

Fix build on Mac OS X

--- config/os/macosx/pThreadUtilities.h.orig	2008-05-29 12:26:05.000000000 +0000
+++ config/os/macosx/pThreadUtilities.h
@@ -66,7 +66,7 @@
 #define __PTHREADUTILITIES_H__
 
 #import "pthread.h"
-#import <CoreServices/../Frameworks/CarbonCore.framework/Headers/MacTypes.h>
+#import <Carbon/Carbon.h> // Really only need <MacTypes.h>, but that has problems on 10.6
 
 #define THREAD_SET_PRIORITY			0
 #define THREAD_SCHEDULED_PRIORITY		1
