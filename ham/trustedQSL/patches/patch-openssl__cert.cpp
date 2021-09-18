$NetBSD: patch-openssl__cert.cpp,v 1.2 2021/09/18 15:03:04 gdt Exp $

\todo Figure out why this is needed, as PATH_MAX is specified by POSIX
to be defined by <limits.h>.

--- src/openssl_cert.cpp.orig	2015-09-20 09:15:24.000000000 +0900
+++ src/openssl_cert.cpp	2015-10-11 01:10:26.000000000 +0900
@@ -131,6 +131,9 @@
 
 #define TQSLLIB_DEF
 
+#ifdef __NetBSD__
+# include "sys/syslimits.h"
+#endif
 
 #include <sys/stat.h>
 #include <sys/types.h>
