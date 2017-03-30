$NetBSD: patch-._stubdom_vtpmmgr_tpm2_marshal.h,v 1.1 2017/03/30 09:15:10 bouyer Exp $
--- ./stubdom/vtpmmgr/tpm2_marshal.h.orig	2017-03-28 16:08:46.000000000 +0200
+++ ./stubdom/vtpmmgr/tpm2_marshal.h	2017-03-28 16:08:56.000000000 +0200
@@ -52,7 +52,7 @@
 #define pack_TPM_BUFFER(ptr, buf, size) pack_BUFFER(ptr, buf, size)
 #define unpack_TPM_BUFFER(ptr, buf, size) unpack_BUFFER(ptr, buf, size)
 
-inline BYTE* pack_BYTE_ARRAY(BYTE* ptr, const BYTE* array, UINT32 size)
+static inline BYTE* pack_BYTE_ARRAY(BYTE* ptr, const BYTE* array, UINT32 size)
 {
     int i;
     for (i = 0; i < size; i++)
@@ -60,22 +60,22 @@
     return ptr;
 }
 
-inline BYTE* pack_TPMA_SESSION(BYTE* ptr, const TPMA_SESSION *attr)
+static inline BYTE* pack_TPMA_SESSION(BYTE* ptr, const TPMA_SESSION *attr)
 {
     return pack_BYTE(ptr, (BYTE)(*attr));
 }
 
-inline BYTE* unpack_TPMA_SESSION(BYTE* ptr, TPMA_SESSION *attr)
+static inline BYTE* unpack_TPMA_SESSION(BYTE* ptr, TPMA_SESSION *attr)
 {
     return unpack_BYTE(ptr, (BYTE *)attr);
 }
 
-inline BYTE* pack_TPMI_ALG_HASH(BYTE* ptr, const TPMI_ALG_HASH *hash)
+static inline BYTE* pack_TPMI_ALG_HASH(BYTE* ptr, const TPMI_ALG_HASH *hash)
 {
     return pack_UINT16(ptr, *hash);
 }
 
-inline BYTE* unpack_TPMI_ALG_HASH(BYTE *ptr, TPMI_ALG_HASH *hash)
+static inline BYTE* unpack_TPMI_ALG_HASH(BYTE *ptr, TPMI_ALG_HASH *hash)
 {
     return unpack_UINT16(ptr, hash);
 }
@@ -125,21 +125,21 @@
 #define pack_TPMI_RH_LOCKOUT(ptr, l)            pack_TPM2_HANDLE(ptr, l)
 #define unpack_TPMI_RH_LOCKOUT(ptr, l)          unpack_TPM2_HANDLE(ptr, l)
 
-inline BYTE* pack_TPM2B_DIGEST(BYTE* ptr, const TPM2B_DIGEST *digest)
+static inline BYTE* pack_TPM2B_DIGEST(BYTE* ptr, const TPM2B_DIGEST *digest)
 {
     ptr = pack_UINT16(ptr, digest->size);
     ptr = pack_BUFFER(ptr, digest->buffer, digest->size);
     return ptr;
 }
 
-inline BYTE* unpack_TPM2B_DIGEST(BYTE* ptr, TPM2B_DIGEST *digest)
+static inline BYTE* unpack_TPM2B_DIGEST(BYTE* ptr, TPM2B_DIGEST *digest)
 {
     ptr = unpack_UINT16(ptr, &digest->size);
     ptr = unpack_BUFFER(ptr, digest->buffer, digest->size);
     return ptr;
 }
 
-inline BYTE* pack_TPMT_TK_CREATION(BYTE* ptr,const TPMT_TK_CREATION *ticket )
+static inline BYTE* pack_TPMT_TK_CREATION(BYTE* ptr,const TPMT_TK_CREATION *ticket )
 {
     ptr = pack_TPM_ST(ptr , &ticket->tag);
     ptr = pack_TPMI_RH_HIERACHY(ptr , &ticket->hierarchy);
@@ -147,7 +147,7 @@
     return ptr;
 }
 
-inline BYTE* unpack_TPMT_TK_CREATION(BYTE* ptr, TPMT_TK_CREATION *ticket )
+static inline BYTE* unpack_TPMT_TK_CREATION(BYTE* ptr, TPMT_TK_CREATION *ticket )
 {
     ptr = unpack_TPM_ST(ptr, &ticket->tag);
     ptr = unpack_TPMI_RH_HIERACHY(ptr, &ticket->hierarchy);
@@ -155,70 +155,70 @@
     return ptr;
 }
 
-inline BYTE* pack_TPM2B_NAME(BYTE* ptr,const TPM2B_NAME *name )
+static inline BYTE* pack_TPM2B_NAME(BYTE* ptr,const TPM2B_NAME *name )
 {
     ptr = pack_UINT16(ptr, name->size);
     ptr = pack_TPM_BUFFER(ptr, name->name, name->size);
     return ptr;
 }
 
-inline BYTE* unpack_TPM2B_NAME(BYTE* ptr, TPM2B_NAME *name)
+static inline BYTE* unpack_TPM2B_NAME(BYTE* ptr, TPM2B_NAME *name)
 {
     ptr = unpack_UINT16(ptr, &name->size);
     ptr = unpack_TPM_BUFFER(ptr, name->name, name->size);
     return ptr;
 }
 
-inline BYTE* pack_TPM2B_NONCE(BYTE* ptr, const TPM2B_NONCE *nonce)
+static inline BYTE* pack_TPM2B_NONCE(BYTE* ptr, const TPM2B_NONCE *nonce)
 {
     return pack_TPM2B_DIGEST(ptr, (const TPM2B_DIGEST*)nonce);
 }
 
 #define unpack_TPM2B_NONCE(ptr, nonce)  unpack_TPM2B_DIGEST(ptr, (TPM2B_DIGEST*)nonce)
 
-inline BYTE* pack_TPM2B_AUTH(BYTE* ptr, const TPM2B_AUTH *auth)
+static inline BYTE* pack_TPM2B_AUTH(BYTE* ptr, const TPM2B_AUTH *auth)
 {
     return pack_TPM2B_DIGEST(ptr, (const TPM2B_DIGEST*)auth);
 }
 
 #define unpack_TPM2B_AUTH(ptr, auth)    unpack_TPM2B_DIGEST(ptr, (TPM2B_DIGEST*)auth)
 
-inline BYTE* pack_TPM2B_DATA(BYTE* ptr, const TPM2B_DATA *data)
+static inline BYTE* pack_TPM2B_DATA(BYTE* ptr, const TPM2B_DATA *data)
 {
     return pack_TPM2B_DIGEST(ptr, (const TPM2B_DIGEST*)data);
 }
 
 #define unpack_TPM2B_DATA(ptr, data)    unpack_TPM2B_DIGEST(ptr, (TPM2B_DIGEST*)data)
 
-inline BYTE* pack_TPM2B_SENSITIVE_DATA(BYTE* ptr, const TPM2B_SENSITIVE_DATA *data)
+static inline BYTE* pack_TPM2B_SENSITIVE_DATA(BYTE* ptr, const TPM2B_SENSITIVE_DATA *data)
 {
     return pack_TPM2B_DIGEST(ptr, (const TPM2B_DIGEST*)data);
 }
 
 #define unpack_TPM2B_SENSITIVE_DATA(ptr, data)  unpack_TPM2B_DIGEST(ptr, (TPM2B_DIGEST*)data)
 
-inline BYTE* pack_TPM2B_PUBLIC_KEY_RSA(BYTE* ptr, const TPM2B_PUBLIC_KEY_RSA *rsa)
+static inline BYTE* pack_TPM2B_PUBLIC_KEY_RSA(BYTE* ptr, const TPM2B_PUBLIC_KEY_RSA *rsa)
 {
     return pack_TPM2B_DIGEST(ptr, (const TPM2B_DIGEST*)rsa);
 }
 
 #define unpack_TPM2B_PUBLIC_KEY_RSA(ptr, rsa)   unpack_TPM2B_DIGEST(ptr, (TPM2B_DIGEST*)rsa)
 
-inline BYTE* pack_TPM2B_PRIVATE(BYTE* ptr, const TPM2B_PRIVATE *Private)
+static inline BYTE* pack_TPM2B_PRIVATE(BYTE* ptr, const TPM2B_PRIVATE *Private)
 {
     ptr = pack_UINT16(ptr, Private->size);
     ptr = pack_TPM_BUFFER(ptr, Private->buffer, Private->size);
     return ptr;
 }
 
-inline BYTE* unpack_TPM2B_PRIVATE(BYTE* ptr, TPM2B_PRIVATE *Private)
+static inline BYTE* unpack_TPM2B_PRIVATE(BYTE* ptr, TPM2B_PRIVATE *Private)
 {
     ptr = unpack_UINT16(ptr, &Private->size);
     ptr = unpack_BUFFER(ptr, Private->buffer, Private->size);
     return ptr;
 }
 
-inline BYTE* pack_TPMS_PCR_SELECTION_ARRAY(BYTE* ptr, const TPMS_PCR_SELECTION *sel, UINT32 count)
+static inline BYTE* pack_TPMS_PCR_SELECTION_ARRAY(BYTE* ptr, const TPMS_PCR_SELECTION *sel, UINT32 count)
 {
     int i;
     for (i = 0; i < count; i++) {
@@ -229,7 +229,7 @@
     return ptr;
 }
 
-inline BYTE* unpack_TPMS_PCR_SELECTION_ARRAY(BYTE* ptr, TPMS_PCR_SELECTION *sel, UINT32 count)
+static inline BYTE* unpack_TPMS_PCR_SELECTION_ARRAY(BYTE* ptr, TPMS_PCR_SELECTION *sel, UINT32 count)
 {
     int i;
     for (i = 0; i < count; i++) {
@@ -240,21 +240,21 @@
     return ptr;
 }
 
-inline BYTE* pack_TPML_PCR_SELECTION(BYTE* ptr, const TPML_PCR_SELECTION *sel)
+static inline BYTE* pack_TPML_PCR_SELECTION(BYTE* ptr, const TPML_PCR_SELECTION *sel)
 {
     ptr = pack_UINT32(ptr, sel->count);
     ptr = pack_TPMS_PCR_SELECTION_ARRAY(ptr, sel->pcrSelections, sel->count);
     return ptr;
 }
 
-inline BYTE* unpack_TPML_PCR_SELECTION(BYTE* ptr, TPML_PCR_SELECTION *sel)
+static inline BYTE* unpack_TPML_PCR_SELECTION(BYTE* ptr, TPML_PCR_SELECTION *sel)
 {
     ptr = unpack_UINT32(ptr, &sel->count);
     ptr = unpack_TPMS_PCR_SELECTION_ARRAY(ptr, sel->pcrSelections, sel->count);
     return ptr;
 }
 
-inline BYTE* unpack_TPML_DIGEST(BYTE* ptr,TPML_DIGEST *digest)
+static inline BYTE* unpack_TPML_DIGEST(BYTE* ptr,TPML_DIGEST *digest)
 {
     int i;
     ptr = unpack_UINT32(ptr, &digest->count);
@@ -265,7 +265,7 @@
     return ptr;
 }
 
-inline BYTE* pack_TPMS_CREATION_DATA(BYTE* ptr,const TPMS_CREATION_DATA *data)
+static inline BYTE* pack_TPMS_CREATION_DATA(BYTE* ptr,const TPMS_CREATION_DATA *data)
 {
     ptr = pack_TPML_PCR_SELECTION(ptr, &data->pcrSelect);
     ptr = pack_TPM2B_DIGEST(ptr, &data->pcrDigest);
@@ -276,7 +276,7 @@
     return ptr;
 }
 
-inline BYTE* unpack_TPMS_CREATION_DATA(BYTE* ptr, TPMS_CREATION_DATA *data)
+static inline BYTE* unpack_TPMS_CREATION_DATA(BYTE* ptr, TPMS_CREATION_DATA *data)
 {
     ptr = unpack_TPML_PCR_SELECTION(ptr, &data->pcrSelect);
     ptr = unpack_TPM2B_DIGEST(ptr, &data->pcrDigest);
@@ -288,28 +288,28 @@
     return ptr;
 }
 
-inline BYTE* pack_TPM2B_CREATION_DATA(BYTE* ptr, const TPM2B_CREATION_DATA *data )
+static inline BYTE* pack_TPM2B_CREATION_DATA(BYTE* ptr, const TPM2B_CREATION_DATA *data )
 {
     ptr = pack_UINT16(ptr, data->size);
     ptr = pack_TPMS_CREATION_DATA(ptr, &data->creationData);
     return ptr;
 }
 
-inline BYTE* unpack_TPM2B_CREATION_DATA(BYTE* ptr, TPM2B_CREATION_DATA * data)
+static inline BYTE* unpack_TPM2B_CREATION_DATA(BYTE* ptr, TPM2B_CREATION_DATA * data)
 {
     ptr = unpack_UINT16(ptr, &data->size);
     ptr = unpack_TPMS_CREATION_DATA(ptr, &data->creationData);
     return ptr;
 }
 
-inline BYTE* pack_TPMS_SENSITIVE_CREATE(BYTE* ptr, const TPMS_SENSITIVE_CREATE *create)
+static inline BYTE* pack_TPMS_SENSITIVE_CREATE(BYTE* ptr, const TPMS_SENSITIVE_CREATE *create)
 {
     ptr = pack_TPM2B_AUTH(ptr, &create->userAuth);
     ptr = pack_TPM2B_SENSITIVE_DATA(ptr, &create->data);
     return ptr;
 }
 
-inline BYTE* pack_TPM2B_SENSITIVE_CREATE(BYTE* ptr, const TPM2B_SENSITIVE_CREATE *create)
+static inline BYTE* pack_TPM2B_SENSITIVE_CREATE(BYTE* ptr, const TPM2B_SENSITIVE_CREATE *create)
 {
     BYTE* sizePtr = ptr;
     ptr += 2;
@@ -318,7 +318,7 @@
     return ptr;
 }
 
-inline BYTE* pack_TPMU_SYM_MODE(BYTE* ptr, const TPMU_SYM_MODE *p,
+static inline BYTE* pack_TPMU_SYM_MODE(BYTE* ptr, const TPMU_SYM_MODE *p,
                                 const TPMI_ALG_SYM_OBJECT *sel)
 {
     switch(*sel) {
@@ -336,7 +336,7 @@
     }
     return ptr;
 }
-inline BYTE* unpack_TPMU_SYM_MODE(BYTE* ptr, TPMU_SYM_MODE *p,
+static inline BYTE* unpack_TPMU_SYM_MODE(BYTE* ptr, TPMU_SYM_MODE *p,
                                   const TPMI_ALG_SYM_OBJECT *sel)
 {
     switch(*sel) {
@@ -355,7 +355,7 @@
     return ptr;
 }
 
-inline BYTE* pack_TPMU_SYM_KEY_BITS(BYTE* ptr, const TPMU_SYM_KEY_BITS *p,
+static inline BYTE* pack_TPMU_SYM_KEY_BITS(BYTE* ptr, const TPMU_SYM_KEY_BITS *p,
                                     const TPMI_ALG_SYM_OBJECT *sel)
 {
     switch(*sel) {
@@ -376,7 +376,7 @@
     return ptr;
 }
 
-inline BYTE* unpack_TPMU_SYM_KEY_BITS(BYTE* ptr, TPMU_SYM_KEY_BITS *p,
+static inline BYTE* unpack_TPMU_SYM_KEY_BITS(BYTE* ptr, TPMU_SYM_KEY_BITS *p,
                                       const TPMI_ALG_SYM_OBJECT *sel)
 {
     switch(*sel) {
@@ -397,7 +397,7 @@
     return ptr;
 }
 
-inline BYTE* pack_TPMT_SYM_DEF_OBJECT(BYTE* ptr, const TPMT_SYM_DEF_OBJECT *p)
+static inline BYTE* pack_TPMT_SYM_DEF_OBJECT(BYTE* ptr, const TPMT_SYM_DEF_OBJECT *p)
 {
     ptr = pack_TPMI_ALG_SYM_OBJECT(ptr, &p->algorithm);
     ptr = pack_TPMU_SYM_KEY_BITS(ptr, &p->keyBits, &p->algorithm);
@@ -405,7 +405,7 @@
     return ptr;
 }
 
-inline BYTE* unpack_TPMT_SYM_DEF_OBJECT(BYTE *ptr, TPMT_SYM_DEF_OBJECT *p)
+static inline BYTE* unpack_TPMT_SYM_DEF_OBJECT(BYTE *ptr, TPMT_SYM_DEF_OBJECT *p)
 {
     ptr = unpack_TPMI_ALG_SYM_OBJECT(ptr, &p->algorithm);
     ptr = unpack_TPMU_SYM_KEY_BITS(ptr, &p->keyBits, &p->algorithm);
@@ -416,7 +416,7 @@
 #define pack_TPMS_SCHEME_OAEP(p, t)     pack_TPMI_ALG_HASH(p, &((t)->hashAlg))
 #define unpack_TPMS_SCHEME_OAEP(p, t)   unpack_TPMI_ALG_HASH(p, &((t)->hashAlg))
 
-inline BYTE* pack_TPMU_ASYM_SCHEME(BYTE *ptr, const TPMU_ASYM_SCHEME *p,
+static inline BYTE* pack_TPMU_ASYM_SCHEME(BYTE *ptr, const TPMU_ASYM_SCHEME *p,
                                    const TPMI_ALG_RSA_SCHEME *s)
 {
     switch(*s) {
@@ -438,7 +438,7 @@
     return ptr;
 }
 
-inline BYTE* unpack_TPMU_ASYM_SCHEME(BYTE *ptr, TPMU_ASYM_SCHEME *p,
+static inline BYTE* unpack_TPMU_ASYM_SCHEME(BYTE *ptr, TPMU_ASYM_SCHEME *p,
                                      const TPMI_ALG_RSA_SCHEME *s)
 {
     switch(*s) {
@@ -462,28 +462,28 @@
     return ptr;
 }
 
-inline BYTE* pack_TPMT_RSA_SCHEME(BYTE* ptr, const TPMT_RSA_SCHEME *p)
+static inline BYTE* pack_TPMT_RSA_SCHEME(BYTE* ptr, const TPMT_RSA_SCHEME *p)
 {
     ptr = pack_TPMI_ALG_RSA_SCHEME(ptr, &p->scheme);
     ptr = pack_TPMU_ASYM_SCHEME(ptr, &p->details, &p->scheme);
     return ptr;
 }
 
-inline BYTE* unpack_TPMT_RSA_SCHEME(BYTE* ptr, TPMT_RSA_SCHEME *p)
+static inline BYTE* unpack_TPMT_RSA_SCHEME(BYTE* ptr, TPMT_RSA_SCHEME *p)
 {
     ptr = unpack_TPMI_ALG_RSA_SCHEME(ptr, &p->scheme);
     ptr = unpack_TPMU_ASYM_SCHEME(ptr, &p->details, &p->scheme);
     return ptr;
 }
 
-inline BYTE* pack_TPMT_RSA_DECRYPT(BYTE* ptr, const TPMT_RSA_DECRYPT *p)
+static inline BYTE* pack_TPMT_RSA_DECRYPT(BYTE* ptr, const TPMT_RSA_DECRYPT *p)
 {
     ptr = pack_TPMI_ALG_RSA_SCHEME(ptr, &p->scheme);
     ptr = pack_TPMU_ASYM_SCHEME(ptr, &p->details, &p->scheme);
     return ptr;
 }
 
-inline BYTE* pack_TPMS_RSA_PARMS(BYTE* ptr, const TPMS_RSA_PARMS *p)
+static inline BYTE* pack_TPMS_RSA_PARMS(BYTE* ptr, const TPMS_RSA_PARMS *p)
 {
     ptr = pack_TPMT_SYM_DEF_OBJECT(ptr, &p->symmetric);
     ptr = pack_TPMT_RSA_SCHEME(ptr, &p->scheme);
@@ -492,7 +492,7 @@
     return ptr;
 }
 
-inline BYTE* unpack_TPMS_RSA_PARMS(BYTE *ptr, TPMS_RSA_PARMS *p)
+static inline BYTE* unpack_TPMS_RSA_PARMS(BYTE *ptr, TPMS_RSA_PARMS *p)
 {
     ptr = unpack_TPMT_SYM_DEF_OBJECT(ptr, &p->symmetric);
     ptr = unpack_TPMT_RSA_SCHEME(ptr, &p->scheme);
@@ -501,7 +501,7 @@
     return ptr;
 }
 
-inline BYTE* pack_TPMU_PUBLIC_PARMS(BYTE* ptr, const TPMU_PUBLIC_PARMS *param,
+static inline BYTE* pack_TPMU_PUBLIC_PARMS(BYTE* ptr, const TPMU_PUBLIC_PARMS *param,
                                     const TPMI_ALG_PUBLIC *selector)
 {
     switch(*selector) {
@@ -518,7 +518,7 @@
     return NULL;
 }
 
-inline BYTE* unpack_TPMU_PUBLIC_PARMS(BYTE* ptr, TPMU_PUBLIC_PARMS *param,
+static inline BYTE* unpack_TPMU_PUBLIC_PARMS(BYTE* ptr, TPMU_PUBLIC_PARMS *param,
                                       const TPMI_ALG_PUBLIC *selector)
 {
     switch(*selector) {
@@ -535,19 +535,19 @@
     return NULL;
 }
 
-inline BYTE* pack_TPMS_ECC_POINT(BYTE* ptr, const TPMS_ECC_POINT *point)
+static inline BYTE* pack_TPMS_ECC_POINT(BYTE* ptr, const TPMS_ECC_POINT *point)
 {
     assert(false);
     return ptr;
 }
 
-inline BYTE* unpack_TPMS_ECC_POINT(BYTE* ptr, TPMS_ECC_POINT *point)
+static inline BYTE* unpack_TPMS_ECC_POINT(BYTE* ptr, TPMS_ECC_POINT *point)
 {
     assert(false);
     return ptr;
 }
 
-inline BYTE* pack_TPMU_PUBLIC_ID(BYTE* ptr, const TPMU_PUBLIC_ID *id,
+static inline BYTE* pack_TPMU_PUBLIC_ID(BYTE* ptr, const TPMU_PUBLIC_ID *id,
                                  const TPMI_ALG_PUBLIC *selector)
 {
     switch (*selector) {
@@ -564,7 +564,7 @@
     return NULL;
 }
 
-inline BYTE* unpack_TPMU_PUBLIC_ID(BYTE* ptr, TPMU_PUBLIC_ID *id, TPMI_ALG_PUBLIC *selector)
+static inline BYTE* unpack_TPMU_PUBLIC_ID(BYTE* ptr, TPMU_PUBLIC_ID *id, TPMI_ALG_PUBLIC *selector)
 {
     switch (*selector) {
     case TPM2_ALG_KEYEDHASH:
@@ -580,7 +580,7 @@
     return NULL;
 }
 
-inline BYTE* pack_TPMT_PUBLIC(BYTE* ptr, const TPMT_PUBLIC *public)
+static inline BYTE* pack_TPMT_PUBLIC(BYTE* ptr, const TPMT_PUBLIC *public)
 {
     ptr = pack_TPMI_ALG_PUBLIC(ptr, &public->type);
     ptr = pack_TPMI_ALG_HASH(ptr, &public->nameAlg);
@@ -591,7 +591,7 @@
     return ptr;
 }
 
-inline BYTE* unpack_TPMT_PUBLIC(BYTE* ptr, TPMT_PUBLIC *public)
+static inline BYTE* unpack_TPMT_PUBLIC(BYTE* ptr, TPMT_PUBLIC *public)
 {
     ptr = unpack_TPMI_ALG_PUBLIC(ptr, &public->type);
     ptr = unpack_TPMI_ALG_HASH(ptr, &public->nameAlg);
@@ -602,7 +602,7 @@
     return ptr;
 }
 
-inline BYTE* pack_TPM2B_PUBLIC(BYTE* ptr, const TPM2B_PUBLIC *public)
+static inline BYTE* pack_TPM2B_PUBLIC(BYTE* ptr, const TPM2B_PUBLIC *public)
 {
     BYTE *sizePtr = ptr;
     ptr += 2;
@@ -611,14 +611,14 @@
     return ptr;
 }
 
-inline BYTE* unpack_TPM2B_PUBLIC(BYTE* ptr, TPM2B_PUBLIC *public)
+static inline BYTE* unpack_TPM2B_PUBLIC(BYTE* ptr, TPM2B_PUBLIC *public)
 {
     ptr = unpack_UINT16(ptr, &public->size);
     ptr = unpack_TPMT_PUBLIC(ptr, &public->publicArea);
     return ptr;
 }
 
-inline BYTE* pack_TPMS_PCR_SELECTION(BYTE* ptr, const TPMS_PCR_SELECTION *selection)
+static inline BYTE* pack_TPMS_PCR_SELECTION(BYTE* ptr, const TPMS_PCR_SELECTION *selection)
 {
     ptr = pack_TPMI_ALG_HASH(ptr, &selection->hash);
     ptr = pack_BYTE(ptr, selection->sizeofSelect);
@@ -626,7 +626,7 @@
     return ptr;
 }
 
-inline BYTE* pack_TPMS_PCR_SELECTION_Array(BYTE* ptr, const TPMS_PCR_SELECTION *selections,
+static inline BYTE* pack_TPMS_PCR_SELECTION_Array(BYTE* ptr, const TPMS_PCR_SELECTION *selections,
                                            const UINT32 cnt)
 {
     int i;
@@ -635,7 +635,7 @@
     return ptr;
 }
 
-inline BYTE* pack_TPM_AuthArea(BYTE* ptr, const TPM_AuthArea *auth)
+static inline BYTE* pack_TPM_AuthArea(BYTE* ptr, const TPM_AuthArea *auth)
 {
     BYTE* sizePtr = ptr;
     ptr += sizeof(UINT32);
@@ -647,7 +647,7 @@
     return ptr;
 }
 
-inline BYTE* unpack_TPM_AuthArea(BYTE* ptr, TPM_AuthArea *auth)
+static inline BYTE* unpack_TPM_AuthArea(BYTE* ptr, TPM_AuthArea *auth)
 {
     ptr = unpack_UINT32(ptr, &auth->size);
     ptr = unpack_TPM_RH(ptr, &auth->sessionHandle);
@@ -657,14 +657,14 @@
     return ptr;
 }
 
-inline BYTE* pack_TPM2_RSA_KEY(BYTE* ptr, const TPM2_RSA_KEY *key)
+static inline BYTE* pack_TPM2_RSA_KEY(BYTE* ptr, const TPM2_RSA_KEY *key)
 {
     ptr = pack_TPM2B_PRIVATE(ptr, &key->Private);
     ptr = pack_TPM2B_PUBLIC(ptr, &key->Public);
     return ptr;
 }
 
-inline BYTE* unpack_TPM2_RSA_KEY(BYTE* ptr, TPM2_RSA_KEY *key)
+static inline BYTE* unpack_TPM2_RSA_KEY(BYTE* ptr, TPM2_RSA_KEY *key)
 {
     ptr = unpack_TPM2B_PRIVATE(ptr, &key->Private);
     ptr = unpack_TPM2B_PUBLIC(ptr, &key->Public);
