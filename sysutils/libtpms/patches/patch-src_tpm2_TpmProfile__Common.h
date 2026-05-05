$NetBSD: patch-src_tpm2_TpmProfile__Common.h,v 1.1 2026/05/05 10:20:02 jperkin Exp $

Support illumos.

--- src/tpm2/TpmProfile_Common.h.orig	2026-05-05 09:42:19.104082485 +0000
+++ src/tpm2/TpmProfile_Common.h
@@ -89,7 +89,7 @@
 #else
 # include <endian.h>
 #endif
-#if defined __linux__ || defined __CYGWIN__
+#if defined __linux__ || defined __CYGWIN__ || defined __illumos__
  #if __BYTE_ORDER == __LITTLE_ENDIAN
   #define  BIG_ENDIAN_TPM       NO
  #endif
