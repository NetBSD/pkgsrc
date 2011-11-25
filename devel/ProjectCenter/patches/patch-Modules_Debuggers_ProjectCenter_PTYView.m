$NetBSD: patch-Modules_Debuggers_ProjectCenter_PTYView.m,v 1.1 2011/11/25 21:35:55 joerg Exp $

--- Modules/Debuggers/ProjectCenter/PTYView.m.orig	2009-01-02 17:51:00.000000000 +0000
+++ Modules/Debuggers/ProjectCenter/PTYView.m
@@ -34,10 +34,6 @@
 #import <stdlib.h>
 #import <string.h>
 
-#if !defined(__OpenBSD__)
-#import <stropts.h>
-#endif
-
 #ifndef NOTIFICATION_CENTER
 #define NOTIFICATION_CENTER [NSNotificationCenter defaultCenter]
 #endif
@@ -48,6 +44,14 @@
 #define USE_FORKPTY_REPLACEMENT 1
 #endif
 
+#ifdef __SOLARIS__
+#import <stropts.h>
+#endif
+
+#if defined (__NetBSD__) || defined (__OpenBSD__)
+#  include <util.h>
+#endif
+
 #if !(defined (__NetBSD__)) && !(defined (__SOLARIS__)) && !(defined (__OpenBSD__))
 #  include <pty.h>
 #endif
