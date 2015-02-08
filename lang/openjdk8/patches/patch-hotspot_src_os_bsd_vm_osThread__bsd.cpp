$NetBSD: patch-hotspot_src_os_bsd_vm_osThread__bsd.cpp,v 1.1 2015/02/08 08:41:25 tnn Exp $

--- hotspot/src/os/bsd/vm/osThread_bsd.cpp.orig	2015-02-02 15:32:37.000000000 +0000
+++ hotspot/src/os/bsd/vm/osThread_bsd.cpp
@@ -30,7 +30,7 @@
 
 void OSThread::pd_initialize() {
   assert(this != NULL, "check");
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(_ALLBSD_SOURCE)
   _thread_id        = 0;
 #else
   _thread_id        = NULL;
