$NetBSD: patch-include_asterisk_sha1.h,v 1.1.1.1 2016/10/25 08:17:05 jnemeth Exp $

--- include/asterisk/sha1.h.orig	2016-09-09 16:14:37.000000000 +0000
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
 
@@ -281,76 +238,6 @@ extern int SHA512FinalBits(SHA512Context
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
-/*
- * HMAC Keyed-Hashing for Message Authentication, RFC 2104,
- * for all SHAs.
- * This interface allows a fixed-length text input to be used.
- */
-extern int hmac(SHAversion whichSha, /* which SHA algorithm to use */
-    const unsigned char *text,     /* pointer to data stream */
-    int text_len,                  /* length of data stream */
-    const unsigned char *key,      /* pointer to authentication key */
-    int key_len,                   /* length of authentication key */
-    uint8_t digest[USHAMaxHashSize]); /* caller digest to fill in */
-
-/*
- * HMAC Keyed-Hashing for Message Authentication, RFC 2104,
- * for all SHAs.
- * This interface allows any length of text input to be used.
- */
-extern int hmacReset(HMACContext *context, enum SHAversion whichSha,
-                     const unsigned char *key, int key_len);
-extern int hmacInput(HMACContext *context, const unsigned char *text,
-                     int text_len);
-extern int hmacFinalBits(HMACContext *context, uint8_t bits,
-                         unsigned int bit_count);
-extern int hmacResult(HMACContext *context,
-                      uint8_t digest[USHAMaxHashSize]);
-
-/*
- * HKDF HMAC-based Extract-and-Expand Key Derivation Function,
- * RFC 5869, for all SHAs.
- */
-extern int hkdf(SHAversion whichSha, const unsigned char *salt,
-                int salt_len, const unsigned char *ikm, int ikm_len,
-                const unsigned char *info, int info_len,
-                uint8_t okm[ ], int okm_len);
-extern int hkdfExtract(SHAversion whichSha, const unsigned char *salt,
-                       int salt_len, const unsigned char *ikm,
-                       int ikm_len, uint8_t prk[USHAMaxHashSize]);
-extern int hkdfExpand(SHAversion whichSha, const uint8_t prk[ ],
-                      int prk_len, const unsigned char *info,
-                      int info_len, uint8_t okm[ ], int okm_len);
-
-/*
- * HKDF HMAC-based Extract-and-Expand Key Derivation Function,
- * RFC 5869, for all SHAs.
- * This interface allows any length of text input to be used.
- */
-extern int hkdfReset(HKDFContext *context, enum SHAversion whichSha,
-                     const unsigned char *salt, int salt_len);
-extern int hkdfInput(HKDFContext *context, const unsigned char *ikm,
-                     int ikm_len);
-extern int hkdfFinalBits(HKDFContext *context, uint8_t ikm_bits,
-                         unsigned int ikm_bit_count);
-extern int hkdfResult(HKDFContext *context,
-                      uint8_t prk[USHAMaxHashSize],
-                      const unsigned char *info, int info_len,
-                      uint8_t okm[USHAMaxHashSize], int okm_len);
-
 /************************ sha-private.h ************************/
 /***************** See RFC 6234 for details. *******************/
 /*
