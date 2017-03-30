$NetBSD: patch-stubdom_vtpmmgr_vtpmmgr.h,v 1.1 2017/03/30 09:15:10 bouyer Exp $
--- stubdom/vtpmmgr/vtpmmgr.h.orig	2017-03-28 16:13:43.000000000 +0200
+++ stubdom/vtpmmgr/vtpmmgr.h	2017-03-28 16:13:51.000000000 +0200
@@ -101,7 +101,7 @@
 
 TPM_RESULT vtpmmgr_handle_cmd(struct tpm_opaque *opq, tpmcmd_t* tpmcmd);
 
-inline TPM_RESULT vtpmmgr_rand(unsigned char* bytes, size_t num_bytes) {
+static inline TPM_RESULT vtpmmgr_rand(unsigned char* bytes, size_t num_bytes) {
    return ctr_drbg_random(&vtpm_globals.ctr_drbg, bytes, num_bytes) == 0 ? 0 : TPM_FAIL;
 }
 
