$NetBSD: patch-src_Xaction.h,v 1.1 2016/06/23 15:17:28 prlw1 Exp $

https://bugs.launchpad.net/bugs/1595562

--- src/Xaction.h.orig	2015-11-09 01:18:50.000000000 +0000
+++ src/Xaction.h
@@ -13,7 +13,6 @@
 #include <libecap/adapter/xaction.h>
 #include <libecap/host/host.h>
 #include <libecap/host/xaction.h>
-#include <libecap/common/memory.h>
 #include <libecap/common/message.h>
 #include <libecap/common/header.h>
 #include <libecap/common/names.h>
@@ -47,7 +46,7 @@ private:
 class Xaction: public libecap::adapter::Xaction, public Antivirus::User
 {
 public:
-    Xaction(libecap::shared_ptr<Service> aService, libecap::host::Xaction *aHostX);
+    Xaction(std::shared_ptr<Service> aService, libecap::host::Xaction *aHostX);
     virtual ~Xaction();
 
     // meta-information for the host transaction
@@ -166,7 +165,7 @@ private:
 
     void disconnect(); // expect no more notifications from Service or Host
 
-    libecap::shared_ptr<const Service> service; // configuration access
+    std::shared_ptr<const Service> service; // configuration access
     libecap::host::Xaction *hostx_; // host transaction representative
     libecap::Area uri; // Request-URI from headers, for logging
 
