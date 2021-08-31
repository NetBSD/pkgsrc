$NetBSD: patch-nss_lib_freebl_sha256-armv8.c,v 1.2 2021/08/31 11:12:30 wiz Exp $

date: 2021-08-27 23:33:18 +0200;  author: mrg;  state: Exp;  commitid: r84ANY9lYgSAJE6D;
fix build on arm64eb: sha512.c and sha256-armv8.c both provided the
same symbols.  (sha256-x86.c has the same problem, but that file
already requires little endian so is not a big deal.)

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
