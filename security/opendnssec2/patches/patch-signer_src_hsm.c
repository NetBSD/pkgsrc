$NetBSD: patch-signer_src_hsm.c,v 1.1 2023/12/05 12:20:40 he Exp $

Work around possible concurrency error and
"[hsm] hsm_get_dnskey(): Got NULL key"
Ref. https://issues.opendnssec.org/browse/SUPPORT-278

--- signer/src/hsm.c.orig	2022-11-08 08:46:49.000000000 +0000
+++ signer/src/hsm.c
@@ -34,6 +34,10 @@
 #include "log.h"
 #include "cryptoki_compat/pkcs11.h"
 
+#include <pthread.h>
+
+pthread_mutex_t _hsm_get_dnskey_mutex = PTHREAD_MUTEX_INITIALIZER;
+
 static const char* hsm_str = "hsm";
 
 /**
@@ -109,7 +113,9 @@ llibhsm_key_start:
 
     /* get dnskey */
     if (!key_id->dnskey) {
+	pthread_mutex_lock(&_hsm_get_dnskey_mutex);
         key_id->dnskey = hsm_get_dnskey(ctx, keylookup(ctx, key_id->locator), key_id->params);
+	pthread_mutex_unlock(&_hsm_get_dnskey_mutex);
     }
     if (!key_id->dnskey) {
         error = hsm_get_error(ctx);
