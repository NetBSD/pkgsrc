$NetBSD: patch-src_klayout.pri,v 1.1 2026/08/07 00:57:21 mef Exp $

required kvm for Timer::memory_size() on NetBSD

--- src/klayout.pri.orig	2026-08-02 03:54:27.675971064 +0000
+++ src/klayout.pri
@@ -238,6 +238,9 @@ msvc {
     LIBS += -lexecinfo
   }
 
+  netbsd {
+    LIBS += -lkvm
+  }
 }
 
 equals(HAVE_QT, "0") {
