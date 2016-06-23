$NetBSD: patch-src_Xaction.cc,v 1.1 2016/06/23 15:17:28 prlw1 Exp $

https://bugs.launchpad.net/bugs/1595562

--- src/Xaction.cc.orig	2015-11-09 01:33:00.000000000 +0000
+++ src/Xaction.cc
@@ -89,7 +89,7 @@ void Adapter::MyAnswer::deliver()
     DebugFun(flXaction) << "exiting " << this
 
 
-Adapter::Xaction::Xaction(libecap::shared_ptr<Service> aService,
+Adapter::Xaction::Xaction(std::shared_ptr<Service> aService,
     libecap::host::Xaction *aHostX):
     serviceRegistration(0),
     service(aService),
@@ -347,7 +347,7 @@ void Adapter::Xaction::noteVbContentDone
 
     vbFile->flush();
 
-    libecap::shared_ptr<Antivirus> scanner = service->scanner;
+    std::shared_ptr<Antivirus> scanner = service->scanner;
     Must(scanner);
 
     if (service->makesAsyncXactions()) {
@@ -411,7 +411,7 @@ void Adapter::Xaction::useVirgin()
 
 void Adapter::Xaction::useStored()
 {
-    libecap::shared_ptr<libecap::Message> adapted = hostx().virgin().clone();
+    std::shared_ptr<libecap::Message> adapted = hostx().virgin().clone();
     Must(adapted != 0);
 
     Must(adapted->body());
