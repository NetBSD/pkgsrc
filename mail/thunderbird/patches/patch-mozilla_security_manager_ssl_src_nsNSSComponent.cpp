$NetBSD: patch-mozilla_security_manager_ssl_src_nsNSSComponent.cpp,v 1.2 2015/07/09 15:17:34 ryoon Exp $

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
