$NetBSD: patch-src_Pointers.h,v 1.1 2016/06/23 15:17:28 prlw1 Exp $

https://bugs.launchpad.net/bugs/1595562

--- src/Pointers.h.orig	2015-11-08 18:07:35.000000000 +0000
+++ src/Pointers.h
@@ -5,15 +5,14 @@
 #ifndef ECAP_CLAMAV_ADAPTER_POINTERS_H
 #define ECAP_CLAMAV_ADAPTER_POINTERS_H
 
-#include <libecap/common/forward.h>
-#include <libecap/common/memory.h>
+#include <memory>
 
 namespace Adapter {
 
     class Xaction;
 
-    typedef libecap::shared_ptr<Xaction> SharedXactionPointer;
-    typedef libecap::weak_ptr<Xaction> XactionPointer;
+    typedef std::shared_ptr<Xaction> SharedXactionPointer;
+    typedef std::weak_ptr<Xaction> XactionPointer;
 
 } // namespace Adapter
 
