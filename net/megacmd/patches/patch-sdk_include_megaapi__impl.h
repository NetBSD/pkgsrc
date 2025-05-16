$NetBSD: patch-sdk_include_megaapi__impl.h,v 1.1 2025/05/16 19:43:58 wiz Exp $

* Use FallbackFileSystemAccess if USE_PERIODIC defined

--- sdk/include/megaapi_impl.h.orig	2025-05-12 14:53:36.536485792 +0200
+++ sdk/include/megaapi_impl.h
@@ -90,6 +90,8 @@ class MegaSemaphore : public CppSemaphor
     class MegaWaiter : public PosixWaiter {};
     #ifdef __APPLE__
     class MegaFileSystemAccess : public MacFileSystemAccess {};
+    #elif defined(USE_PERIODIC)
+    class MegaFileSystemAccess : public FallbackFileSystemAccess {};
     #else
     class MegaFileSystemAccess : public LinuxFileSystemAccess {};
     #endif
