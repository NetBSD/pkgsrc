$NetBSD: patch-openssl__cert.cpp,v 1.1 2015/10/11 02:59:07 mef Exp $

error: 'PATH_MAX' was not declared in this scope

--- src/openssl_cert.cpp.orig	2015-09-20 09:15:24.000000000 +0900
+++ src/openssl_cert.cpp	2015-10-11 01:10:26.000000000 +0900
@@ -131,6 +131,9 @@
 
 #define TQSLLIB_DEF
 
+#ifdef __NetBSD__
+# include "sys/syslimits.h"
+#endif
 
 #include <sys/stat.h>
 #include <sys/types.h>
