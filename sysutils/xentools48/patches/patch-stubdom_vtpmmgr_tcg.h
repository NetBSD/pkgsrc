$NetBSD: patch-stubdom_vtpmmgr_tcg.h,v 1.1 2017/03/30 09:15:10 bouyer Exp $
--- stubdom/vtpmmgr/tcg.h.orig	2017-03-28 16:00:31.000000000 +0200
+++ stubdom/vtpmmgr/tcg.h	2017-03-28 16:01:01.000000000 +0200
@@ -461,7 +461,7 @@
    BYTE* vendorSpecific;
 } TPM_CAP_VERSION_INFO;
 
-inline void free_TPM_CAP_VERSION_INFO(TPM_CAP_VERSION_INFO* v) {
+static inline void free_TPM_CAP_VERSION_INFO(TPM_CAP_VERSION_INFO* v) {
    free(v->vendorSpecific);
    v->vendorSpecific = NULL;
 }
@@ -494,7 +494,7 @@
    BYTE* data;
 } TPM_SYMMETRIC_KEY;
 
-inline void free_TPM_SYMMETRIC_KEY_PARMS(TPM_SYMMETRIC_KEY_PARMS* p) {
+static inline void free_TPM_SYMMETRIC_KEY_PARMS(TPM_SYMMETRIC_KEY_PARMS* p) {
    free(p->IV);
    p->IV = NULL;
 }
@@ -510,7 +510,7 @@
 
 #define TPM_RSA_KEY_PARMS_INIT { 0, 0, 0, NULL }
 
-inline void free_TPM_RSA_KEY_PARMS(TPM_RSA_KEY_PARMS* p) {
+static inline void free_TPM_RSA_KEY_PARMS(TPM_RSA_KEY_PARMS* p) {
    free(p->exponent);
    p->exponent = NULL;
 }
@@ -528,7 +528,7 @@
 
 #define TPM_KEY_PARMS_INIT { 0, 0, 0, 0 }
 
-inline void free_TPM_KEY_PARMS(TPM_KEY_PARMS* p) {
+static inline void free_TPM_KEY_PARMS(TPM_KEY_PARMS* p) {
    if(p->parmSize) {
       switch(p->algorithmID) {
          case TPM_ALG_RSA:
@@ -550,7 +550,7 @@
 
 #define TPM_STORE_PUBKEY_INIT { 0, NULL }
 
-inline void free_TPM_STORE_PUBKEY(TPM_STORE_PUBKEY* p) {
+static inline void free_TPM_STORE_PUBKEY(TPM_STORE_PUBKEY* p) {
    free(p->key);
    p->key = NULL;
 }
@@ -562,7 +562,7 @@
 
 #define TPM_PUBKEY_INIT { TPM_KEY_PARMS_INIT, TPM_STORE_PUBKEY_INIT }
 
-inline void free_TPM_PUBKEY(TPM_PUBKEY* k) {
+static inline void free_TPM_PUBKEY(TPM_PUBKEY* k) {
    free_TPM_KEY_PARMS(&k->algorithmParms);
    free_TPM_STORE_PUBKEY(&k->pubKey);
 }
@@ -574,7 +574,7 @@
 
 #define TPM_PCR_SELECTION_INIT { 0, NULL }
 
-inline void free_TPM_PCR_SELECTION(TPM_PCR_SELECTION* p) {
+static inline void free_TPM_PCR_SELECTION(TPM_PCR_SELECTION* p) {
    free(p->pcrSelect);
    p->pcrSelect = NULL;
 }
@@ -594,7 +594,7 @@
 #define TPM_PCR_INFO_LONG_INIT { 0, 0, 0, TPM_PCR_SELECTION_INIT, \
                                  TPM_PCR_SELECTION_INIT }
 
-inline void free_TPM_PCR_INFO_LONG(TPM_PCR_INFO_LONG* p) {
+static inline void free_TPM_PCR_INFO_LONG(TPM_PCR_INFO_LONG* p) {
    free_TPM_PCR_SELECTION(&p->creationPCRSelection);
    free_TPM_PCR_SELECTION(&p->releasePCRSelection);
 }
@@ -607,7 +607,7 @@
 
 #define TPM_PCR_INFO_INIT { TPM_PCR_SELECTION_INIT }
 
-inline void free_TPM_PCR_INFO(TPM_PCR_INFO* p) {
+static inline void free_TPM_PCR_INFO(TPM_PCR_INFO* p) {
    free_TPM_PCR_SELECTION(&p->pcrSelection);
 }
 
@@ -619,7 +619,7 @@
 
 #define TPM_PCR_COMPOSITE_INIT { TPM_PCR_SELECTION_INIT, 0, NULL }
 
-inline void free_TPM_PCR_COMPOSITE(TPM_PCR_COMPOSITE* p) {
+static inline void free_TPM_PCR_COMPOSITE(TPM_PCR_COMPOSITE* p) {
    free_TPM_PCR_SELECTION(&p->select);
    free(p->pcrValue);
    p->pcrValue = NULL;
@@ -643,7 +643,7 @@
    .pubKey = TPM_STORE_PUBKEY_INIT, \
    .encDataSize = 0, .encData = NULL }
 
-inline void free_TPM_KEY(TPM_KEY* k) {
+static inline void free_TPM_KEY(TPM_KEY* k) {
    if(k->PCRInfoSize) {
       free_TPM_PCR_INFO(&k->PCRInfo);
    }
@@ -660,7 +660,7 @@
 
 #define TPM_BOUND_DATA_INIT { .payloadData = NULL }
 
-inline void free_TPM_BOUND_DATA(TPM_BOUND_DATA* d) {
+static inline void free_TPM_BOUND_DATA(TPM_BOUND_DATA* d) {
    free(d->payloadData);
    d->payloadData = NULL;
 }
@@ -676,7 +676,7 @@
 #define TPM_STORED_DATA_INIT { .sealInfoSize = 0, sealInfo = TPM_PCR_INFO_INIT,\
    .encDataSize = 0, .encData = NULL }
 
-inline void free_TPM_STORED_DATA(TPM_STORED_DATA* d) {
+static inline void free_TPM_STORED_DATA(TPM_STORED_DATA* d) {
    if(d->sealInfoSize) {
       free_TPM_PCR_INFO(&d->sealInfo);
    }
@@ -696,7 +696,7 @@
 #define TPM_STORED_DATA12_INIT { .sealInfoLongSize = 0, \
    sealInfoLong = TPM_PCR_INFO_INIT, .encDataSize = 0, .encData = NULL }
 
-inline void free_TPM_STORED_DATA12(TPM_STORED_DATA12* d) {
+static inline void free_TPM_STORED_DATA12(TPM_STORED_DATA12* d) {
    if(d->sealInfoLongSize) {
       free_TPM_PCR_INFO_LONG(&d->sealInfoLong);
    }
