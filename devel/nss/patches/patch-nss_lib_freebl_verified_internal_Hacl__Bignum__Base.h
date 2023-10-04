$NetBSD: patch-nss_lib_freebl_verified_internal_Hacl__Bignum__Base.h,v 1.1 2023/10/04 11:49:22 jperkin Exp $

SunOS needs alloca.h.

--- nss/lib/freebl/verified/internal/Hacl_Bignum_Base.h.orig	2023-10-02 12:17:27.000000000 +0000
+++ nss/lib/freebl/verified/internal/Hacl_Bignum_Base.h
@@ -29,6 +29,9 @@
 extern "C" {
 #endif
 
+#ifdef __sun
+#include <alloca.h>
+#endif
 #include <string.h>
 #include "krml/internal/types.h"
 #include "krml/internal/builtin.h"
