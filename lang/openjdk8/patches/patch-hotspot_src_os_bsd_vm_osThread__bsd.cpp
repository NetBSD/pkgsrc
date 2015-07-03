$NetBSD: patch-hotspot_src_os_bsd_vm_osThread__bsd.cpp,v 1.3 2015/07/03 20:40:59 fhajny Exp $

--- hotspot/src/os/bsd/vm/osThread_bsd.cpp.orig	2015-06-10 10:31:51.000000000 +0000
+++ hotspot/src/os/bsd/vm/osThread_bsd.cpp
@@ -30,7 +30,7 @@
 
 void OSThread::pd_initialize() {
   assert(this != NULL, "check");
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(_ALLBSD_SOURCE)
   _thread_id        = 0;
 #else
   _thread_id        = NULL;
