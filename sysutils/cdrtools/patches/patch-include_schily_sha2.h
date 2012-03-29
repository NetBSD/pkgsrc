$NetBSD: patch-include_schily_sha2.h,v 1.2 2012/03/29 14:51:59 wiz Exp $

Fix clang-3.1 build:
sha2.c:1001:2: error: call to 'SHA384Pad' is ambiguous
        SHA384Pad(context);
        ^~~~~~~~~
../include/schily/sha2.h:110:13: note: candidate function
extern void SHA384Pad           __PR((SHA2_CTX *));
            ^
sha2.c:969:14: note: candidate function
#pragma weak SHA384Pad = SHA512Pad
             ^
1 error generated.

--- include/schily/sha2.h.orig	2010-08-27 10:41:30.000000000 +0000
+++ include/schily/sha2.h
@@ -104,10 +104,12 @@ extern char *SHA256Data		__PR((const UIn
 
 #ifdef	HAVE_LONGLONG
 extern void SHA384Init		__PR((SHA2_CTX *));
+#ifndef  HAVE_PRAGMA_WEAK
 extern void SHA384Transform	__PR((UInt64_t state[8],
 					const UInt8_t [SHA384_BLOCK_LENGTH]));
 extern void SHA384Update	__PR((SHA2_CTX *, const UInt8_t *, size_t));
 extern void SHA384Pad		__PR((SHA2_CTX *));
+#endif
 extern void SHA384Final		__PR((UInt8_t [SHA384_DIGEST_LENGTH],
 					SHA2_CTX *));
 extern char *SHA384End		__PR((SHA2_CTX *, char *));
