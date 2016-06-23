$NetBSD: patch-src_Service.cc,v 1.1 2016/06/23 15:17:28 prlw1 Exp $

https://bugs.launchpad.net/bugs/1595562

--- src/Service.cc.orig	2015-11-09 01:12:46.000000000 +0000
+++ src/Service.cc
@@ -177,7 +177,7 @@ void Adapter::Service::setAll(const Opti
     tmpFileNameTemplate = TmpFileNameTemplateDefault;
 
     // TODO: convert to std::unique_ptr when we require C++11.
-    const std::auto_ptr<TricklingConfig> oldTricklingConfig(tricklingConfig_);
+    const std::unique_ptr<TricklingConfig> oldTricklingConfig(tricklingConfig_);
     tricklingConfig_ = new TricklingConfig();
 
     Cfgtor cfgtor(*this);
@@ -339,7 +339,7 @@ Adapter::Service::MadeXactionPointer
 Adapter::Service::makeXaction(libecap::host::Xaction *hostx)
 {
     checkpoint();
-    const libecap::shared_ptr<Service> s = std::tr1::static_pointer_cast<Service>(self);
+    const std::shared_ptr<Service> s = std::static_pointer_cast<Service>(self);
     SharedXactionPointer x(new Xaction(s, hostx));
     x->self = x;
     x->serviceRegistration = new Xactions::iterator(xactions->insert(xactions->end(), x));
@@ -385,7 +385,7 @@ Adapter::Service::tricklingConfig()
     return *tricklingConfig_;
 }
 
-void Adapter::Service::finalizeTricklingConfig(const std::auto_ptr<TricklingConfig> &oldConfig)
+void Adapter::Service::finalizeTricklingConfig(const std::unique_ptr<TricklingConfig> &oldConfig)
 {
     if (!tricklingConfig_->dropSize) {
         // TODO: Warn if at least one other trickling option was explicitly configured.
