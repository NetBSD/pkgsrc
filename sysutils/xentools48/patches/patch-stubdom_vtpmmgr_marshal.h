$NetBSD: patch-stubdom_vtpmmgr_marshal.h,v 1.1 2017/03/30 09:15:10 bouyer Exp $
--- stubdom/vtpmmgr/marshal.h.orig	2017-03-28 16:07:11.000000000 +0200
+++ stubdom/vtpmmgr/marshal.h	2017-03-28 16:08:28.000000000 +0200
@@ -47,17 +47,17 @@
 	UNPACK_ALLOC
 } UnpackPtr;
 
-inline BYTE* pack_BYTE(BYTE* ptr, BYTE t) {
+static inline BYTE* pack_BYTE(BYTE* ptr, BYTE t) {
 	ptr[0] = t;
 	return ++ptr;
 }
 
-inline BYTE* unpack_BYTE(BYTE* ptr, BYTE* t) {
+static inline BYTE* unpack_BYTE(BYTE* ptr, BYTE* t) {
 	t[0] = ptr[0];
 	return ++ptr;
 }
 
-inline int unpack3_BYTE(BYTE* ptr, UINT32* pos, UINT32 max, BYTE *t)
+static inline int unpack3_BYTE(BYTE* ptr, UINT32* pos, UINT32 max, BYTE *t)
 {
 	if (*pos + 1 > max)
 		return TPM_SIZE;
@@ -72,19 +72,19 @@
 #define unpack3_BOOL(p, x, m, t) unpack3_BYTE(p, x, m, t)
 #define sizeof_BOOL(t) 1
 
-inline BYTE* pack_UINT16(void* ptr, UINT16 t) {
+static inline BYTE* pack_UINT16(void* ptr, UINT16 t) {
 	UINT16* p = ptr;
 	*p = cpu_to_be16(t);
 	return ptr + sizeof(UINT16);
 }
 
-inline BYTE* unpack_UINT16(void* ptr, UINT16* t) {
+static inline BYTE* unpack_UINT16(void* ptr, UINT16* t) {
 	UINT16* p = ptr;
 	*t = be16_to_cpu(*p);
 	return ptr + sizeof(UINT16);
 }
 
-inline int unpack3_UINT16(BYTE* ptr, UINT32* pos, UINT32 max, UINT16 *t)
+static inline int unpack3_UINT16(BYTE* ptr, UINT32* pos, UINT32 max, UINT16 *t)
 {
 	if (*pos + 2 > max)
 		return TPM_SIZE;
@@ -93,19 +93,19 @@
 	return 0;
 }
 
-inline BYTE* pack_UINT32(void* ptr, UINT32 t) {
+static inline BYTE* pack_UINT32(void* ptr, UINT32 t) {
 	UINT32* p = ptr;
 	*p = cpu_to_be32(t);
 	return ptr + sizeof(UINT32);
 }
 
-inline BYTE* unpack_UINT32(void* ptr, UINT32* t) {
+static inline BYTE* unpack_UINT32(void* ptr, UINT32* t) {
 	UINT32* p = ptr;
 	*t = be32_to_cpu(*p);
 	return ptr + sizeof(UINT32);
 }
 
-inline int unpack3_UINT32(BYTE* ptr, UINT32* pos, UINT32 max, UINT32 *t)
+static inline int unpack3_UINT32(BYTE* ptr, UINT32* pos, UINT32 max, UINT32 *t)
 {
 	if (*pos + 4 > max)
 		return TPM_SIZE;
@@ -236,17 +236,17 @@
 #define sizeof_TCS_KEY_HANDLE(t) sizeof_UINT32(t)
 
 
-inline BYTE* pack_BUFFER(BYTE* ptr, const BYTE* buf, UINT32 size) {
+static inline BYTE* pack_BUFFER(BYTE* ptr, const BYTE* buf, UINT32 size) {
 	memcpy(ptr, buf, size);
 	return ptr + size;
 }
 
-inline BYTE* unpack_BUFFER(BYTE* ptr, BYTE* buf, UINT32 size) {
+static inline BYTE* unpack_BUFFER(BYTE* ptr, BYTE* buf, UINT32 size) {
 	memcpy(buf, ptr, size);
 	return ptr + size;
 }
 
-inline int unpack3_BUFFER(BYTE* ptr, UINT32* pos, UINT32 max, BYTE* buf, UINT32 size) {
+static inline int unpack3_BUFFER(BYTE* ptr, UINT32* pos, UINT32 max, BYTE* buf, UINT32 size) {
 	if (*pos + size > max)
 		return TPM_SIZE;
 	memcpy(buf, ptr + *pos, size);
@@ -256,12 +256,12 @@
 
 #define sizeof_BUFFER(b, s) s
 
-inline BYTE* unpack_ALIAS(BYTE* ptr, BYTE** buf, UINT32 size) {
+static inline BYTE* unpack_ALIAS(BYTE* ptr, BYTE** buf, UINT32 size) {
 	*buf = ptr;
 	return ptr + size;
 }
 
-inline BYTE* unpack_ALLOC(BYTE* ptr, BYTE** buf, UINT32 size) {
+static inline BYTE* unpack_ALLOC(BYTE* ptr, BYTE** buf, UINT32 size) {
 	if(size) {
 		*buf = malloc(size);
 		memcpy(*buf, ptr, size);
@@ -271,7 +271,7 @@
 	return ptr + size;
 }
 
-inline BYTE* unpack_PTR(BYTE* ptr, BYTE** buf, UINT32 size, UnpackPtr alloc) {
+static inline BYTE* unpack_PTR(BYTE* ptr, BYTE** buf, UINT32 size, UnpackPtr alloc) {
 	if(alloc == UNPACK_ALLOC) {
 		return unpack_ALLOC(ptr, buf, size);
 	} else {
@@ -279,7 +279,7 @@
 	}
 }
 
-inline int unpack3_PTR(BYTE* ptr, UINT32* pos, UINT32 max, BYTE** buf, UINT32 size, UnpackPtr alloc) {
+static inline int unpack3_PTR(BYTE* ptr, UINT32* pos, UINT32 max, BYTE** buf, UINT32 size, UnpackPtr alloc) {
 	if (size > max || *pos + size > max)
 		return TPM_SIZE;
 	if (alloc == UNPACK_ALLOC) {
@@ -292,15 +292,15 @@
 }
 #define unpack3_VPTR(ptr, pos, max, buf, size, alloc) unpack3_PTR(ptr, pos, max, (void*)(buf), size, alloc)
 
-inline BYTE* pack_TPM_AUTHDATA(BYTE* ptr, const TPM_AUTHDATA* d) {
+static inline BYTE* pack_TPM_AUTHDATA(BYTE* ptr, const TPM_AUTHDATA* d) {
 	return pack_BUFFER(ptr, *d, TPM_DIGEST_SIZE);
 }
 
-inline BYTE* unpack_TPM_AUTHDATA(BYTE* ptr, TPM_AUTHDATA* d) {
+static inline BYTE* unpack_TPM_AUTHDATA(BYTE* ptr, TPM_AUTHDATA* d) {
 	return unpack_BUFFER(ptr, *d, TPM_DIGEST_SIZE);
 }
 
-inline int unpack3_TPM_AUTHDATA(BYTE* ptr, UINT32* pos, UINT32 len, TPM_AUTHDATA* d) {
+static inline int unpack3_TPM_AUTHDATA(BYTE* ptr, UINT32* pos, UINT32 len, TPM_AUTHDATA* d) {
 	return unpack3_BUFFER(ptr, pos, len, *d, TPM_DIGEST_SIZE);
 }
 
@@ -325,7 +325,7 @@
 #define sizeof_TPM_TAG(t) sizeof_UINT16(t)
 #define sizeof_TPM_STRUCTURE_TAG(t) sizeof_UINT16(t)
 
-inline BYTE* pack_TPM_VERSION(BYTE* ptr, const TPM_VERSION* t) {
+static inline BYTE* pack_TPM_VERSION(BYTE* ptr, const TPM_VERSION* t) {
 	ptr[0] = t->major;
 	ptr[1] = t->minor;
 	ptr[2] = t->revMajor;
@@ -333,7 +333,7 @@
 	return ptr + 4;
 }
 
-inline BYTE* unpack_TPM_VERSION(BYTE* ptr, TPM_VERSION* t) {
+static inline BYTE* unpack_TPM_VERSION(BYTE* ptr, TPM_VERSION* t) {
 	t->major = ptr[0];
 	t->minor = ptr[1];
 	t->revMajor = ptr[2];
@@ -341,7 +341,7 @@
 	return ptr + 4;
 }
 
-inline int unpack3_TPM_VERSION(BYTE* ptr, UINT32 *pos, UINT32 max, TPM_VERSION* t) {
+static inline int unpack3_TPM_VERSION(BYTE* ptr, UINT32 *pos, UINT32 max, TPM_VERSION* t) {
 	if (*pos + 4 > max)
 		return TPM_SIZE;
 	ptr += *pos;
@@ -355,7 +355,7 @@
 
 #define sizeof_TPM_VERSION(x) 4
 
-inline BYTE* pack_TPM_CAP_VERSION_INFO(BYTE* ptr, const TPM_CAP_VERSION_INFO* v) {
+static inline BYTE* pack_TPM_CAP_VERSION_INFO(BYTE* ptr, const TPM_CAP_VERSION_INFO* v) {
 	ptr = pack_TPM_STRUCTURE_TAG(ptr, v->tag);
 	ptr = pack_TPM_VERSION(ptr, &v->version);
 	ptr = pack_UINT16(ptr, v->specLevel);
@@ -366,7 +366,7 @@
 	return ptr;
 }
 
-inline BYTE* unpack_TPM_CAP_VERSION_INFO(BYTE* ptr, TPM_CAP_VERSION_INFO* v, UnpackPtr alloc) {
+static inline BYTE* unpack_TPM_CAP_VERSION_INFO(BYTE* ptr, TPM_CAP_VERSION_INFO* v, UnpackPtr alloc) {
 	ptr = unpack_TPM_STRUCTURE_TAG(ptr, &v->tag);
 	ptr = unpack_TPM_VERSION(ptr, &v->version);
 	ptr = unpack_UINT16(ptr, &v->specLevel);
@@ -377,15 +377,15 @@
 	return ptr;
 }
 
-inline BYTE* pack_TPM_DIGEST(BYTE* ptr, const TPM_DIGEST* d) {
+static inline BYTE* pack_TPM_DIGEST(BYTE* ptr, const TPM_DIGEST* d) {
 	return pack_BUFFER(ptr, d->digest, TPM_DIGEST_SIZE);
 }
 
-inline BYTE* unpack_TPM_DIGEST(BYTE* ptr, TPM_DIGEST* d) {
+static inline BYTE* unpack_TPM_DIGEST(BYTE* ptr, TPM_DIGEST* d) {
 	return unpack_BUFFER(ptr, d->digest, TPM_DIGEST_SIZE);
 }
 
-inline int unpack3_TPM_DIGEST(BYTE* ptr, UINT32* pos, UINT32 max, TPM_DIGEST* d) {
+static inline int unpack3_TPM_DIGEST(BYTE* ptr, UINT32* pos, UINT32 max, TPM_DIGEST* d) {
 	return unpack3_BUFFER(ptr, pos, max, d->digest, TPM_DIGEST_SIZE);
 }
 
@@ -409,72 +409,72 @@
 #define pack_TPM_CHOSENID_HASH(ptr, d) pack_TPM_DIGEST(ptr, d)
 #define unpack_TPM_CHOSENID_HASH(ptr, d) unpack_TPM_DIGEST(ptr, d)
 
-inline BYTE* pack_TPM_NONCE(BYTE* ptr, const TPM_NONCE* n) {
+static inline BYTE* pack_TPM_NONCE(BYTE* ptr, const TPM_NONCE* n) {
 	return pack_BUFFER(ptr, n->nonce, TPM_DIGEST_SIZE);
 }
 
-inline BYTE* unpack_TPM_NONCE(BYTE* ptr, TPM_NONCE* n) {
+static inline BYTE* unpack_TPM_NONCE(BYTE* ptr, TPM_NONCE* n) {
 	return unpack_BUFFER(ptr, n->nonce, TPM_DIGEST_SIZE);
 }
 
 #define sizeof_TPM_NONCE(x) TPM_DIGEST_SIZE
 
-inline int unpack3_TPM_NONCE(BYTE* ptr, UINT32* pos, UINT32 max, TPM_NONCE* n) {
+static inline int unpack3_TPM_NONCE(BYTE* ptr, UINT32* pos, UINT32 max, TPM_NONCE* n) {
 	return unpack3_BUFFER(ptr, pos, max, n->nonce, TPM_DIGEST_SIZE);
 }
 
-inline BYTE* pack_TPM_SYMMETRIC_KEY_PARMS(BYTE* ptr, const TPM_SYMMETRIC_KEY_PARMS* k) {
+static inline BYTE* pack_TPM_SYMMETRIC_KEY_PARMS(BYTE* ptr, const TPM_SYMMETRIC_KEY_PARMS* k) {
 	ptr = pack_UINT32(ptr, k->keyLength);
 	ptr = pack_UINT32(ptr, k->blockSize);
 	ptr = pack_UINT32(ptr, k->ivSize);
 	return pack_BUFFER(ptr, k->IV, k->ivSize);
 }
 
-inline BYTE* pack_TPM_SYMMETRIC_KEY(BYTE* ptr, const TPM_SYMMETRIC_KEY* k) {
+static inline BYTE* pack_TPM_SYMMETRIC_KEY(BYTE* ptr, const TPM_SYMMETRIC_KEY* k) {
 	ptr = pack_UINT32(ptr, k->algId);
 	ptr = pack_UINT16(ptr, k->encScheme);
 	ptr = pack_UINT16(ptr, k->size);
 	return pack_BUFFER(ptr, k->data, k->size);
 }
 
-inline int unpack3_TPM_SYMMETRIC_KEY_PARMS(BYTE* ptr, UINT32* pos, UINT32 max, TPM_SYMMETRIC_KEY_PARMS* k, UnpackPtr alloc) {
+static inline int unpack3_TPM_SYMMETRIC_KEY_PARMS(BYTE* ptr, UINT32* pos, UINT32 max, TPM_SYMMETRIC_KEY_PARMS* k, UnpackPtr alloc) {
 	return unpack3_UINT32(ptr, pos, max, &k->keyLength) ||
 		unpack3_UINT32(ptr, pos, max, &k->blockSize) ||
 		unpack3_UINT32(ptr, pos, max, &k->ivSize) ||
 		unpack3_PTR(ptr, pos, max, &k->IV, k->ivSize, alloc);
 }
 
-inline int sizeof_TPM_SYMMETRIC_KEY_PARMS(const TPM_SYMMETRIC_KEY_PARMS* k) {
+static inline int sizeof_TPM_SYMMETRIC_KEY_PARMS(const TPM_SYMMETRIC_KEY_PARMS* k) {
 	return 12 + k->ivSize;
 }
 
-inline int unpack3_TPM_SYMMETRIC_KEY(BYTE* ptr, UINT32* pos, UINT32 max, TPM_SYMMETRIC_KEY* k, UnpackPtr alloc) {
+static inline int unpack3_TPM_SYMMETRIC_KEY(BYTE* ptr, UINT32* pos, UINT32 max, TPM_SYMMETRIC_KEY* k, UnpackPtr alloc) {
 	return unpack3_UINT32(ptr, pos, max, &k->algId) ||
 		unpack3_UINT16(ptr, pos, max, &k->encScheme) ||
 		unpack3_UINT16(ptr, pos, max, &k->size) ||
 		unpack3_PTR(ptr, pos, max, &k->data, k->size, alloc);
 }
 
-inline BYTE* pack_TPM_RSA_KEY_PARMS(BYTE* ptr, const TPM_RSA_KEY_PARMS* k) {
+static inline BYTE* pack_TPM_RSA_KEY_PARMS(BYTE* ptr, const TPM_RSA_KEY_PARMS* k) {
 	ptr = pack_UINT32(ptr, k->keyLength);
 	ptr = pack_UINT32(ptr, k->numPrimes);
 	ptr = pack_UINT32(ptr, k->exponentSize);
 	return pack_BUFFER(ptr, k->exponent, k->exponentSize);
 }
 
-inline int unpack3_TPM_RSA_KEY_PARMS(BYTE* ptr, UINT32* pos, UINT32 max, TPM_RSA_KEY_PARMS* k, UnpackPtr alloc) {
+static inline int unpack3_TPM_RSA_KEY_PARMS(BYTE* ptr, UINT32* pos, UINT32 max, TPM_RSA_KEY_PARMS* k, UnpackPtr alloc) {
 	return unpack3_UINT32(ptr, pos, max, &k->keyLength) ||
 		unpack3_UINT32(ptr, pos, max, &k->numPrimes) ||
 		unpack3_UINT32(ptr, pos, max, &k->exponentSize) ||
 		unpack3_PTR(ptr, pos, max, &k->exponent, k->exponentSize, alloc);
 }
 
-inline int sizeof_TPM_RSA_KEY_PARMS(const TPM_RSA_KEY_PARMS* k) {
+static inline int sizeof_TPM_RSA_KEY_PARMS(const TPM_RSA_KEY_PARMS* k) {
 	return 12 + k->exponentSize;
 }
 
 
-inline BYTE* pack_TPM_KEY_PARMS(BYTE* ptr, const TPM_KEY_PARMS* k) {
+static inline BYTE* pack_TPM_KEY_PARMS(BYTE* ptr, const TPM_KEY_PARMS* k) {
 	ptr = pack_TPM_ALGORITHM_ID(ptr, k->algorithmID);
 	ptr = pack_TPM_ENC_SCHEME(ptr, k->encScheme);
 	ptr = pack_TPM_SIG_SCHEME(ptr, k->sigScheme);
@@ -493,7 +493,7 @@
 	return ptr;
 }
 
-inline int unpack3_TPM_KEY_PARMS(BYTE* ptr, UINT32* pos, UINT32 len, TPM_KEY_PARMS* k, UnpackPtr alloc) {
+static inline int unpack3_TPM_KEY_PARMS(BYTE* ptr, UINT32* pos, UINT32 len, TPM_KEY_PARMS* k, UnpackPtr alloc) {
 	int rc = unpack3_TPM_ALGORITHM_ID(ptr, pos, len, &k->algorithmID) ||
 		unpack3_TPM_ENC_SCHEME(ptr, pos, len, &k->encScheme) ||
 		unpack3_TPM_SIG_SCHEME(ptr, pos, len, &k->sigScheme) ||
@@ -511,7 +511,7 @@
 	return TPM_FAIL;
 }
 
-inline int sizeof_TPM_KEY_PARMS(const TPM_KEY_PARMS* k) {
+static inline int sizeof_TPM_KEY_PARMS(const TPM_KEY_PARMS* k) {
 	int rc = 0;
 	rc += sizeof_TPM_ALGORITHM_ID(&k->algorithmID);
 	rc += sizeof_TPM_ENC_SCHEME(&k->encScheme);
@@ -532,66 +532,66 @@
 	return rc;
 }
 
-inline BYTE* pack_TPM_STORE_PUBKEY(BYTE* ptr, const TPM_STORE_PUBKEY* k) {
+static inline BYTE* pack_TPM_STORE_PUBKEY(BYTE* ptr, const TPM_STORE_PUBKEY* k) {
 	ptr = pack_UINT32(ptr, k->keyLength);
 	ptr = pack_BUFFER(ptr, k->key, k->keyLength);
 	return ptr;
 }
 
-inline int unpack3_TPM_STORE_PUBKEY(BYTE* ptr, UINT32* pos, UINT32 max, TPM_STORE_PUBKEY* k, UnpackPtr alloc) {
+static inline int unpack3_TPM_STORE_PUBKEY(BYTE* ptr, UINT32* pos, UINT32 max, TPM_STORE_PUBKEY* k, UnpackPtr alloc) {
 	return unpack3_UINT32(ptr, pos, max, &k->keyLength) ||
 		unpack3_PTR(ptr, pos, max, &k->key, k->keyLength, alloc);
 }
 
-inline int sizeof_TPM_STORE_PUBKEY(const TPM_STORE_PUBKEY* k) {
+static inline int sizeof_TPM_STORE_PUBKEY(const TPM_STORE_PUBKEY* k) {
 	return 4 + k->keyLength;
 }
 
-inline BYTE* pack_TPM_PUBKEY(BYTE* ptr, const TPM_PUBKEY* k) {
+static inline BYTE* pack_TPM_PUBKEY(BYTE* ptr, const TPM_PUBKEY* k) {
 	ptr = pack_TPM_KEY_PARMS(ptr, &k->algorithmParms);
 	return pack_TPM_STORE_PUBKEY(ptr, &k->pubKey);
 }
 
-inline int unpack3_TPM_PUBKEY(BYTE* ptr, UINT32* pos, UINT32 len, TPM_PUBKEY* k, UnpackPtr alloc) {
+static inline int unpack3_TPM_PUBKEY(BYTE* ptr, UINT32* pos, UINT32 len, TPM_PUBKEY* k, UnpackPtr alloc) {
 	return unpack3_TPM_KEY_PARMS(ptr, pos, len, &k->algorithmParms, alloc) ||
 		unpack3_TPM_STORE_PUBKEY(ptr, pos, len, &k->pubKey, alloc);
 }
 
-inline BYTE* pack_TPM_PCR_SELECTION(BYTE* ptr, const TPM_PCR_SELECTION* p) {
+static inline BYTE* pack_TPM_PCR_SELECTION(BYTE* ptr, const TPM_PCR_SELECTION* p) {
 	ptr = pack_UINT16(ptr, p->sizeOfSelect);
 	ptr = pack_BUFFER(ptr, p->pcrSelect, p->sizeOfSelect);
 	return ptr;
 }
 
-inline BYTE* unpack_TPM_PCR_SELECTION(BYTE* ptr, TPM_PCR_SELECTION* p, UnpackPtr alloc) {
+static inline BYTE* unpack_TPM_PCR_SELECTION(BYTE* ptr, TPM_PCR_SELECTION* p, UnpackPtr alloc) {
 	ptr = unpack_UINT16(ptr, &p->sizeOfSelect);
 	ptr = unpack_PTR(ptr, &p->pcrSelect, p->sizeOfSelect, alloc);
 	return ptr;
 }
 
-inline int unpack3_TPM_PCR_SELECTION(BYTE* ptr, UINT32* pos, UINT32 max, TPM_PCR_SELECTION* p, UnpackPtr alloc) {
+static inline int unpack3_TPM_PCR_SELECTION(BYTE* ptr, UINT32* pos, UINT32 max, TPM_PCR_SELECTION* p, UnpackPtr alloc) {
 	return unpack3_UINT16(ptr, pos, max, &p->sizeOfSelect) ||
 		unpack3_PTR(ptr, pos, max, &p->pcrSelect, p->sizeOfSelect, alloc);
 }
 
-inline int sizeof_TPM_PCR_SELECTION(const TPM_PCR_SELECTION* p) {
+static inline int sizeof_TPM_PCR_SELECTION(const TPM_PCR_SELECTION* p) {
 	return 2 + p->sizeOfSelect;
 }
 
-inline BYTE* pack_TPM_PCR_INFO(BYTE* ptr, const TPM_PCR_INFO* p) {
+static inline BYTE* pack_TPM_PCR_INFO(BYTE* ptr, const TPM_PCR_INFO* p) {
 	ptr = pack_TPM_PCR_SELECTION(ptr, &p->pcrSelection);
 	ptr = pack_TPM_COMPOSITE_HASH(ptr, &p->digestAtRelease);
 	ptr = pack_TPM_COMPOSITE_HASH(ptr, &p->digestAtCreation);
 	return ptr;
 }
 
-inline int unpack3_TPM_PCR_INFO(BYTE* ptr, UINT32* pos, UINT32 max, TPM_PCR_INFO* p, UnpackPtr alloc) {
+static inline int unpack3_TPM_PCR_INFO(BYTE* ptr, UINT32* pos, UINT32 max, TPM_PCR_INFO* p, UnpackPtr alloc) {
 	return unpack3_TPM_PCR_SELECTION(ptr, pos, max, &p->pcrSelection, alloc) ||
 		unpack3_TPM_COMPOSITE_HASH(ptr, pos, max, &p->digestAtRelease) ||
 		unpack3_TPM_COMPOSITE_HASH(ptr, pos, max, &p->digestAtCreation);
 }
 
-inline int sizeof_TPM_PCR_INFO(const TPM_PCR_INFO* p) {
+static inline int sizeof_TPM_PCR_INFO(const TPM_PCR_INFO* p) {
 	int rc = 0;
 	rc += sizeof_TPM_PCR_SELECTION(&p->pcrSelection);
 	rc += sizeof_TPM_COMPOSITE_HASH(&p->digestAtRelease);
@@ -599,7 +599,7 @@
 	return rc;
 }
 
-inline BYTE* pack_TPM_PCR_INFO_LONG(BYTE* ptr, const TPM_PCR_INFO_LONG* p) {
+static inline BYTE* pack_TPM_PCR_INFO_LONG(BYTE* ptr, const TPM_PCR_INFO_LONG* p) {
 	ptr = pack_TPM_STRUCTURE_TAG(ptr, p->tag);
 	ptr = pack_TPM_LOCALITY_SELECTION(ptr, p->localityAtCreation);
 	ptr = pack_TPM_LOCALITY_SELECTION(ptr, p->localityAtRelease);
@@ -610,7 +610,7 @@
 	return ptr;
 }
 
-inline int sizeof_TPM_PCR_INFO_LONG(const TPM_PCR_INFO_LONG* p) {
+static inline int sizeof_TPM_PCR_INFO_LONG(const TPM_PCR_INFO_LONG* p) {
 	int rc = 0;
 	rc += sizeof_TPM_STRUCTURE_TAG(p->tag);
 	rc += sizeof_TPM_LOCALITY_SELECTION(p->localityAtCreation);
@@ -622,7 +622,7 @@
 	return rc;
 }
 
-inline int unpack3_TPM_PCR_INFO_LONG(BYTE* ptr, UINT32* pos, UINT32 max, TPM_PCR_INFO_LONG* p, UnpackPtr alloc) {
+static inline int unpack3_TPM_PCR_INFO_LONG(BYTE* ptr, UINT32* pos, UINT32 max, TPM_PCR_INFO_LONG* p, UnpackPtr alloc) {
 	return unpack3_TPM_STRUCTURE_TAG(ptr, pos, max, &p->tag) ||
 		unpack3_TPM_LOCALITY_SELECTION(ptr, pos, max,
 					       &p->localityAtCreation) ||
@@ -637,20 +637,20 @@
 		unpack3_TPM_COMPOSITE_HASH(ptr, pos, max, &p->digestAtRelease);
 }
 
-inline BYTE* pack_TPM_PCR_COMPOSITE(BYTE* ptr, const TPM_PCR_COMPOSITE* p) {
+static inline BYTE* pack_TPM_PCR_COMPOSITE(BYTE* ptr, const TPM_PCR_COMPOSITE* p) {
 	ptr = pack_TPM_PCR_SELECTION(ptr, &p->select);
 	ptr = pack_UINT32(ptr, p->valueSize);
 	ptr = pack_BUFFER(ptr, (const BYTE*)p->pcrValue, p->valueSize);
 	return ptr;
 }
 
-inline int unpack3_TPM_PCR_COMPOSITE(BYTE* ptr, UINT32* pos, UINT32 max, TPM_PCR_COMPOSITE* p, UnpackPtr alloc) {
+static inline int unpack3_TPM_PCR_COMPOSITE(BYTE* ptr, UINT32* pos, UINT32 max, TPM_PCR_COMPOSITE* p, UnpackPtr alloc) {
 	return unpack3_TPM_PCR_SELECTION(ptr, pos, max, &p->select, alloc) ||
 		unpack3_UINT32(ptr, pos, max, &p->valueSize) ||
 		unpack3_PTR(ptr, pos, max, (BYTE**)&p->pcrValue, p->valueSize, alloc);
 }
 
-inline BYTE* pack_TPM_KEY(BYTE* ptr, const TPM_KEY* k) {
+static inline BYTE* pack_TPM_KEY(BYTE* ptr, const TPM_KEY* k) {
 	ptr = pack_TPM_VERSION(ptr, &k->ver);
 	ptr = pack_TPM_KEY_USAGE(ptr, k->keyUsage);
 	ptr = pack_TPM_KEY_FLAGS(ptr, k->keyFlags);
@@ -665,7 +665,7 @@
 	return pack_BUFFER(ptr, k->encData, k->encDataSize);
 }
 
-inline int unpack3_TPM_KEY(BYTE* ptr, UINT32* pos, UINT32 max, TPM_KEY* k, UnpackPtr alloc) {
+static inline int unpack3_TPM_KEY(BYTE* ptr, UINT32* pos, UINT32 max, TPM_KEY* k, UnpackPtr alloc) {
 	int rc = unpack3_TPM_VERSION(ptr, pos, max, &k->ver) ||
 		unpack3_TPM_KEY_USAGE(ptr, pos, max, &k->keyUsage) ||
 		unpack3_TPM_KEY_FLAGS(ptr, pos, max, &k->keyFlags) ||
@@ -682,7 +682,7 @@
 		unpack3_PTR(ptr, pos, max, &k->encData, k->encDataSize, alloc);
 }
 
-inline int sizeof_TPM_KEY(const TPM_KEY* k) {
+static inline int sizeof_TPM_KEY(const TPM_KEY* k) {
 	int rc = 0;
 	rc += sizeof_TPM_VERSION(&k->ver);
 	rc += sizeof_TPM_KEY_USAGE(k->keyUsage);
@@ -699,19 +699,19 @@
 	return rc;
 }
 
-inline BYTE* pack_TPM_BOUND_DATA(BYTE* ptr, const TPM_BOUND_DATA* b, UINT32 payloadSize) {
+static inline BYTE* pack_TPM_BOUND_DATA(BYTE* ptr, const TPM_BOUND_DATA* b, UINT32 payloadSize) {
 	ptr = pack_TPM_VERSION(ptr, &b->ver);
 	ptr = pack_TPM_PAYLOAD_TYPE(ptr, b->payload);
 	return pack_BUFFER(ptr, b->payloadData, payloadSize);
 }
 
-inline BYTE* unpack_TPM_BOUND_DATA(BYTE* ptr, TPM_BOUND_DATA* b, UINT32 payloadSize, UnpackPtr alloc) {
+static inline BYTE* unpack_TPM_BOUND_DATA(BYTE* ptr, TPM_BOUND_DATA* b, UINT32 payloadSize, UnpackPtr alloc) {
 	ptr = unpack_TPM_VERSION(ptr, &b->ver);
 	ptr = unpack_TPM_PAYLOAD_TYPE(ptr, &b->payload);
 	return unpack_PTR(ptr, &b->payloadData, payloadSize, alloc);
 }
 
-inline BYTE* pack_TPM_STORED_DATA(BYTE* ptr, const TPM_STORED_DATA* d) {
+static inline BYTE* pack_TPM_STORED_DATA(BYTE* ptr, const TPM_STORED_DATA* d) {
 	ptr = pack_TPM_VERSION(ptr, &d->ver);
 	ptr = pack_UINT32(ptr, d->sealInfoSize);
 	if(d->sealInfoSize) {
@@ -722,7 +722,7 @@
 	return ptr;
 }
 
-inline int sizeof_TPM_STORED_DATA(const TPM_STORED_DATA* d) {
+static inline int sizeof_TPM_STORED_DATA(const TPM_STORED_DATA* d) {
 	int rv = sizeof_TPM_VERSION(&d->ver) + sizeof_UINT32(d->sealInfoSize);
 	if (d->sealInfoSize) {
 		rv += sizeof_TPM_PCR_INFO(&d->sealInfo);
@@ -732,7 +732,7 @@
 	return rv;
 }
 
-inline int unpack3_TPM_STORED_DATA(BYTE* ptr, UINT32* pos, UINT32 len, TPM_STORED_DATA* d, UnpackPtr alloc) {
+static inline int unpack3_TPM_STORED_DATA(BYTE* ptr, UINT32* pos, UINT32 len, TPM_STORED_DATA* d, UnpackPtr alloc) {
 	int rc = unpack3_TPM_VERSION(ptr, pos, len, &d->ver) ||
 		unpack3_UINT32(ptr, pos, len, &d->sealInfoSize);
 	if (rc)
@@ -746,7 +746,7 @@
 	return rc;
 }
 
-inline BYTE* pack_TPM_STORED_DATA12(BYTE* ptr, const TPM_STORED_DATA12* d) {
+static inline BYTE* pack_TPM_STORED_DATA12(BYTE* ptr, const TPM_STORED_DATA12* d) {
 	ptr = pack_TPM_STRUCTURE_TAG(ptr, d->tag);
 	ptr = pack_TPM_ENTITY_TYPE(ptr, d->et);
 	ptr = pack_UINT32(ptr, d->sealInfoLongSize);
@@ -758,7 +758,7 @@
 	return ptr;
 }
 
-inline int sizeof_TPM_STORED_DATA12(const TPM_STORED_DATA12* d) {
+static inline int sizeof_TPM_STORED_DATA12(const TPM_STORED_DATA12* d) {
 	int rv = sizeof_TPM_STRUCTURE_TAG(&d->ver) +
 		 sizeof_TPM_ENTITY_TYPE(&d->et) +
 		 sizeof_UINT32(d->sealInfoLongSize);
@@ -770,7 +770,7 @@
 	return rv;
 }
 
-inline int unpack3_TPM_STORED_DATA12(BYTE* ptr, UINT32* pos, UINT32 len, TPM_STORED_DATA12* d, UnpackPtr alloc) {
+static inline int unpack3_TPM_STORED_DATA12(BYTE* ptr, UINT32* pos, UINT32 len, TPM_STORED_DATA12* d, UnpackPtr alloc) {
 	int rc = unpack3_TPM_STRUCTURE_TAG(ptr, pos, len, &d->tag) ||
 		unpack3_TPM_ENTITY_TYPE(ptr, pos, len, &d->et) ||
 		unpack3_UINT32(ptr, pos, len, &d->sealInfoLongSize);
@@ -786,7 +786,7 @@
 	return rc;
 }
 
-inline BYTE* pack_TPM_AUTH_SESSION(BYTE* ptr, const TPM_AUTH_SESSION* auth) {
+static inline BYTE* pack_TPM_AUTH_SESSION(BYTE* ptr, const TPM_AUTH_SESSION* auth) {
 	ptr = pack_TPM_AUTH_HANDLE(ptr, auth->AuthHandle);
 	ptr = pack_TPM_NONCE(ptr, &auth->NonceOdd);
 	ptr = pack_BOOL(ptr, auth->fContinueAuthSession);
@@ -794,21 +794,21 @@
 	return ptr;
 }
 
-inline BYTE* unpack_TPM_AUTH_SESSION(BYTE* ptr, TPM_AUTH_SESSION* auth) {
+static inline BYTE* unpack_TPM_AUTH_SESSION(BYTE* ptr, TPM_AUTH_SESSION* auth) {
 	ptr = unpack_TPM_NONCE(ptr, &auth->NonceEven);
 	ptr = unpack_BOOL(ptr, &auth->fContinueAuthSession);
 	ptr = unpack_TPM_AUTHDATA(ptr, &auth->HMAC);
 	return ptr;
 }
 
-inline int unpack3_TPM_AUTH_SESSION(BYTE* ptr, UINT32* pos, UINT32 len, TPM_AUTH_SESSION* auth) {
+static inline int unpack3_TPM_AUTH_SESSION(BYTE* ptr, UINT32* pos, UINT32 len, TPM_AUTH_SESSION* auth) {
 	return unpack3_TPM_NONCE(ptr, pos, len, &auth->NonceEven) ||
 		unpack3_BOOL(ptr, pos, len, &auth->fContinueAuthSession) ||
 		unpack3_TPM_AUTHDATA(ptr, pos, len, &auth->HMAC);
 }
 
 
-inline int sizeof_TPM_AUTH_SESSION(const TPM_AUTH_SESSION* auth) {
+static inline int sizeof_TPM_AUTH_SESSION(const TPM_AUTH_SESSION* auth) {
 	int rv = 0;
 	rv += sizeof_TPM_AUTH_HANDLE(auth->AuthHandle);
 	rv += sizeof_TPM_NONCE(&auth->NonceOdd);
@@ -817,7 +817,7 @@
 	return rv;
 }
 
-inline BYTE* pack_TPM_RQU_HEADER(BYTE* ptr,
+static inline BYTE* pack_TPM_RQU_HEADER(BYTE* ptr,
 		TPM_TAG tag,
 		UINT32 size,
 		TPM_COMMAND_CODE ord) {
@@ -826,7 +826,7 @@
 	return pack_UINT32(ptr, ord);
 }
 
-inline BYTE* unpack_TPM_RQU_HEADER(BYTE* ptr,
+static inline BYTE* unpack_TPM_RQU_HEADER(BYTE* ptr,
 		TPM_TAG* tag,
 		UINT32* size,
 		TPM_COMMAND_CODE* ord) {
@@ -836,7 +836,7 @@
 	return ptr;
 }
 
-inline int unpack3_TPM_RQU_HEADER(BYTE* ptr, UINT32* pos, UINT32 max,
+static inline int unpack3_TPM_RQU_HEADER(BYTE* ptr, UINT32* pos, UINT32 max,
 		TPM_TAG* tag, UINT32* size, TPM_COMMAND_CODE* ord) {
 	return
 		unpack3_UINT16(ptr, pos, max, tag) ||
