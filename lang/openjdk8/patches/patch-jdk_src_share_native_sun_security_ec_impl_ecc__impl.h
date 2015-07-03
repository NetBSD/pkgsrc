$NetBSD: patch-jdk_src_share_native_sun_security_ec_impl_ecc__impl.h,v 1.1 2015/07/03 20:40:59 fhajny Exp $

GCC compatability.

--- jdk/src/share/native/sun/security/ec/impl/ecc_impl.h.orig	2015-06-10 10:36:26.000000000 +0000
+++ jdk/src/share/native/sun/security/ec/impl/ecc_impl.h
@@ -38,12 +38,13 @@
 
 #ifndef _ECC_IMPL_H
 #define _ECC_IMPL_H
+  
+#include <sys/types.h>
 
 #ifdef __cplusplus
 extern "C" {
 #endif
 
-#include <sys/types.h>
 #include "ecl-exp.h"
 
 /*
@@ -57,6 +58,11 @@ typedef unsigned long ulong_t;
 typedef enum { B_FALSE, B_TRUE } boolean_t;
 #endif /* __linux__ */
 
+#if defined(__solaris__) && defined(_GNU_SOURCE) && defined(_XOPEN_SOURCE)
+#define B_FALSE _B_FALSE
+#define B_TRUE _B_TRUE
+#endif /* __solaris__ && _GNU_SOURCE */
+
 #ifdef _ALLBSD_SOURCE
 #include <stdint.h>
 #define B_FALSE FALSE
