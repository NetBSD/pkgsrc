$NetBSD: patch-include_asterisk_sha1.h,v 1.2 2022/03/04 12:22:31 ryoon Exp $

--- include/asterisk/sha1.h.orig	2022-02-10 11:53:37.000000000 +0000
+++ include/asterisk/sha1.h
@@ -191,49 +191,6 @@ typedef struct SHA256Context SHA224Conte
 typedef struct SHA512Context SHA384Context;
 
 /*
- *  This structure holds context information for all SHA
- *  hashing operations.
- */
-typedef struct USHAContext {
-	int whichSha;               /* which SHA is being used */
-	union {
-		SHA1Context sha1Context;
-		SHA224Context sha224Context; SHA256Context sha256Context;
-		SHA384Context sha384Context; SHA512Context sha512Context;
-	} ctx;
-} USHAContext;
-
-/*
- *  This structure will hold context information for the HMAC
- *  keyed-hashing operation.
- */
-typedef struct HMACContext {
-	int whichSha;               /* which SHA is being used */
-	int hashSize;               /* hash size of SHA being used */
-	int blockSize;              /* block size of SHA being used */
-	USHAContext shaContext;     /* SHA context */
-	unsigned char k_opad[USHA_Max_Message_Block_Size];
-	/* outer padding - key XORd with opad */
-	int Computed;               /* Is the MAC computed? */
-	int Corrupted;              /* Cumulative corruption code */
-
-} HMACContext;
-
-/*
- *  This structure will hold context information for the HKDF
- *  extract-and-expand Key Derivation Functions.
- */
-typedef struct HKDFContext {
-	int whichSha;               /* which SHA is being used */
-	HMACContext hmacContext;
-	int hashSize;               /* hash size of SHA being used */
-	unsigned char prk[USHAMaxHashSize];
-	/* pseudo-random key - output of hkdfInput */
-	int Computed;               /* Is the key material computed? */
-	int Corrupted;              /* Cumulative corruption code */
-} HKDFContext;
-
-/*
  *  Function Prototypes
  */
 
@@ -281,19 +238,6 @@ extern int SHA512FinalBits(SHA512Context
 extern int SHA512Result(SHA512Context *,
                         uint8_t Message_Digest[SHA512HashSize]);
 
-/* Unified SHA functions, chosen by whichSha */
-extern int USHAReset(USHAContext *context, SHAversion whichSha);
-extern int USHAInput(USHAContext *context,
-                     const uint8_t *bytes, unsigned int bytecount);
-extern int USHAFinalBits(USHAContext *context,
-                         uint8_t bits, unsigned int bit_count);
-extern int USHAResult(USHAContext *context,
-                      uint8_t Message_Digest[USHAMaxHashSize]);
-extern int USHABlockSize(enum SHAversion whichSha);
-extern int USHAHashSize(enum SHAversion whichSha);
-extern int USHAHashSizeBits(enum SHAversion whichSha);
-extern const char *USHAHashName(enum SHAversion whichSha);
-
 /************************ sha-private.h ************************/
 /***************** See RFC 6234 for details. *******************/
 /*
