$NetBSD: patch-config_os_macosx_pThreadUtilities.h,v 1.1 2014/08/16 21:01:38 gls Exp $

Fix build on Mac OS X

--- config/os/macosx/pThreadUtilities.h.orig	2008-05-29 12:26:05.000000000 +0000
+++ config/os/macosx/pThreadUtilities.h
@@ -66,7 +66,7 @@
 #define __PTHREADUTILITIES_H__
 
 #import "pthread.h"
-#import <CoreServices/../Frameworks/CarbonCore.framework/Headers/MacTypes.h>
+#import <MacTypes.h>
 
 #define THREAD_SET_PRIORITY			0
 #define THREAD_SCHEDULED_PRIORITY		1
