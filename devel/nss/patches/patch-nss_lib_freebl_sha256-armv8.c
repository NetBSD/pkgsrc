--- nss/lib/freebl/sha256-armv8.c.orig	2021-08-05 01:03:36.000000000 -0700
+++ nss/lib/freebl/sha256-armv8.c	2021-08-27 14:21:56.160037512 -0700
@@ -2,7 +2,7 @@
  * License, v. 2.0. If a copy of the MPL was not distributed with this
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
-#ifdef USE_HW_SHA2
+#if defined(USE_HW_SHA2) && defined(IS_LITTLE_ENDIAN)
 
 #ifndef __ARM_FEATURE_CRYPTO
 #error "Compiler option is invalid"
@@ -200,4 +200,4 @@ SHA256_Update_Native(SHA256Context *ctx,
     }
 }
 
-#endif /* USE_HW_SHA2 */
+#endif /* USE_HW_SHA2 && IS_LITTLE_ENDIAN */
