$NetBSD: patch-security_manager_ssl_src_nsNSSComponent.cpp,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- security/manager/ssl/src/nsNSSComponent.cpp.orig	2014-10-11 09:06:44.000000000 +0000
+++ security/manager/ssl/src/nsNSSComponent.cpp
@@ -53,6 +53,7 @@
 #include "nss.h"
 #include "pkix/pkixnss.h"
 #include "ssl.h"
+#define NSS_ENABLE_ECC 1
 #include "sslproto.h"
 #include "secmod.h"
 #include "secerr.h"
