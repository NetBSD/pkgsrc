$NetBSD: patch-mozilla_security_manager_ssl_src_nsNSSComponent.cpp,v 1.1 2016/04/17 18:22:21 ryoon Exp $

--- mozilla/security/manager/ssl/src/nsNSSComponent.cpp.orig	2015-06-08 17:49:16.000000000 +0000
+++ mozilla/security/manager/ssl/src/nsNSSComponent.cpp
@@ -43,6 +43,7 @@
 #include "nss.h"
 #include "pkix/pkixnss.h"
 #include "ssl.h"
+#define NSS_ENABLE_ECC 1
 #include "sslproto.h"
 #include "secmod.h"
 #include "secerr.h"
