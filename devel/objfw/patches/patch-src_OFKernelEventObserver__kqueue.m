$NetBSD: patch-src_OFKernelEventObserver__kqueue.m,v 1.1 2022/08/15 14:56:04 ryoon Exp $

* Fix build for kqueue under NetBSD.

--- src/OFKernelEventObserver_kqueue.m.orig	2017-10-23 21:05:22.000000000 +0000
+++ src/OFKernelEventObserver_kqueue.m
@@ -97,7 +97,7 @@
 #ifndef OF_NETBSD
 	event.udata = object;
 #else
-	event.udata = (intptr_t)object;
+	event.udata = (__typeof__(event.udata))object;
 #endif
 
 	if (kevent(_kernelQueue, &event, 1, NULL, 0, NULL) != 0)
@@ -116,7 +116,7 @@
 #ifndef OF_NETBSD
 	event.udata = object;
 #else
-	event.udata = (intptr_t)object;
+	event.udata = (__typeof__(event.udata))object;
 #endif
 
 	if (kevent(_kernelQueue, &event, 1, NULL, 0, NULL) != 0)
