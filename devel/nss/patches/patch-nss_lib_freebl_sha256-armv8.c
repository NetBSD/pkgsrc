$NetBSD: patch-nss_lib_freebl_sha256-armv8.c,v 1.3 2021/09/01 09:40:46 mrg Exp $


fix build on arm64eb: sha512.c and sha256-armv8.c both provided the
same symbols.  (sha256-x86.c has the same problem, but that file
already requires little endian so is not a big deal.)

XXX  this is really strange.  the code in sha512.c uses:

#if !defined(USE_HW_SHA2) || !defined(IS_LITTLE_ENDIAN)

which originally this patch attempted to match, but IS_LITTLE_ENDIAN
is never defined inside nss, even though it's used a few dozen times.
there is a MP_IS_LITTLE_ENDIAN defined that is setup, but almost
never used.


--- nss/lib/freebl/sha256-armv8.c.orig	2021-08-05 01:03:36.000000000 -0700
+++ nss/lib/freebl/sha256-armv8.c	2021-09-01 01:59:50.464034605 -0700
@@ -2,7 +2,7 @@
  * License, v. 2.0. If a copy of the MPL was not distributed with this
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
-#ifdef USE_HW_SHA2
+#if defined(USE_HW_SHA2) && !defined(__ARM_BIG_ENDIAN)
 
 #ifndef __ARM_FEATURE_CRYPTO
 #error "Compiler option is invalid"
@@ -200,4 +200,4 @@ SHA256_Update_Native(SHA256Context *ctx,
     }
 }
 
-#endif /* USE_HW_SHA2 */
+#endif /* USE_HW_SHA2 && !__ARM_BIG_ENDIAN */
