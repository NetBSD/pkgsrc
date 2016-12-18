$NetBSD: patch-sha.h,v 1.1 2016/12/18 21:50:08 joerg Exp $

--- sha.h.orig	2016-12-18 16:47:35.780062621 +0000
+++ sha.h
@@ -246,12 +246,12 @@ extern int USHAHashSizeBits (enum SHAver
  * for all SHAs.
  * This interface allows a fixed-length text input to be used.
  */
-extern int hmac (SHAversion whichSha,	/* which SHA algorithm to use */
-		 const unsigned char *text,	/* pointer to data stream */
-		 int text_len,	/* length of data stream */
-		 const unsigned char *key,	/* pointer to authentication key */
-		 int key_len,	/* length of authentication key */
-		 uint8_t digest[USHAMaxHashSize]);	/* caller digest to fill in */
+extern int ykhmac (SHAversion whichSha,	/* which SHA algorithm to use */
+		   const unsigned char *text,	/* pointer to data stream */
+		   int text_len,	/* length of data stream */
+		   const unsigned char *key,	/* pointer to authentication key */
+		   int key_len,	/* length of authentication key */
+		   uint8_t digest[USHAMaxHashSize]);	/* caller digest to fill in */
 
 /*
  * HMAC Keyed-Hashing for Message Authentication, RFC2104,
