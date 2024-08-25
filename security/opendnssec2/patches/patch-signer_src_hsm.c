$NetBSD: patch-signer_src_hsm.c,v 1.2 2024/08/25 17:15:50 he Exp $

Work around possible concurrency error and
"[hsm] hsm_get_dnskey(): Got NULL key"
Ref. https://issues.opendnssec.org/browse/SUPPORT-278

--- signer/src/hsm.c.orig	2022-11-08 08:46:49.000000000 +0000
+++ signer/src/hsm.c
@@ -33,6 +33,10 @@
 #include "hsm.h"
 #include "log.h"
 
+#include <pthread.h>
+
+pthread_mutex_t _hsm_get_dnskey_mutex = PTHREAD_MUTEX_INITIALIZER;
+
 static const char* hsm_str = "hsm";
 
 /**
@@ -108,7 +112,9 @@ llibhsm_key_start:
 
     /* get dnskey */
     if (!key_id->dnskey) {
+	pthread_mutex_lock(&_hsm_get_dnskey_mutex);
         key_id->dnskey = hsm_get_dnskey(ctx, keylookup(ctx, key_id->locator), key_id->params);
+	pthread_mutex_unlock(&_hsm_get_dnskey_mutex);
     }
     if (!key_id->dnskey) {
         error = hsm_get_error(ctx);
