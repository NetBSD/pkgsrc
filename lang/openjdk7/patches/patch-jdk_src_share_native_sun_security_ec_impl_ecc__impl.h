$NetBSD: patch-jdk_src_share_native_sun_security_ec_impl_ecc__impl.h,v 1.2 2018/07/24 16:07:25 jperkin Exp $

GCC compatability.

--- jdk/src/share/native/sun/security/ec/impl/ecc_impl.h.orig	2017-08-13 05:55:20.000000000 +0000
+++ jdk/src/share/native/sun/security/ec/impl/ecc_impl.h
@@ -39,12 +39,13 @@
 
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
@@ -58,6 +59,11 @@ typedef unsigned long ulong_t;
 typedef enum { B_FALSE, B_TRUE } boolean_t;
 #endif /* __linux__ */
 
+#if defined(__solaris__) && defined(__XOPEN_OR_POSIX)
+#define B_FALSE _B_FALSE
+#define B_TRUE _B_TRUE
+#endif /* __solaris__ && _GNU_SOURCE */
+
 #ifdef _ALLBSD_SOURCE
 #include <stdint.h>
 #define B_FALSE FALSE
