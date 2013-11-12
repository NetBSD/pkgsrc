$NetBSD: patch-mozilla_security_manager_ssl_src_nsNSSComponent.cpp,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/security/manager/ssl/src/nsNSSComponent.cpp.orig	2013-10-23 22:09:16.000000000 +0000
+++ mozilla/security/manager/ssl/src/nsNSSComponent.cpp
@@ -49,6 +49,7 @@
 
 #include "nss.h"
 #include "ssl.h"
+#define NSS_ENABLE_ECC 1
 #include "sslproto.h"
 #include "secmod.h"
 #include "secmime.h"
