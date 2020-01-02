$NetBSD: patch-file.cc,v 1.1 2020/01/02 09:56:49 tsutsui Exp $

Don't use unaligned word copy that won't work on RISC CPUs.

--- file.cc.orig	2008-01-06 06:20:00.000000000 +0000
+++ file.cc
@@ -1719,13 +1719,7 @@ public:
 		lsrc += 2;
 	}
 	static void Copy1Pixel(const char*& lsrc, char*& ldest) {
-#ifdef WORDS_BIGENDIAN
-		ldest[0] = lsrc[0];
-		ldest[1] = lsrc[1];
-		ldest[2] = lsrc[2];
-#else /* LITTLE ENDIAN / intel architecture */
-		*(int*)ldest = *(int*)lsrc; ldest[3]=0;
-#endif
+		memcpy(ldest, lsrc, 3);
 		lsrc += 3; ldest += 4;
 	}
 	static int ProcessBlockSize(void) {
@@ -1862,13 +1856,7 @@ public:
 		lsrc += 2;
 	}
 	static void Copy1Pixel(const char*& lsrc, char*& ldest) {
-#ifdef WORDS_BIGENDIAN
-		ldest[0] = lsrc[0];
-		ldest[1] = lsrc[1];
-		ldest[2] = lsrc[2];
-#else /* LITTLE ENDIAN / intel architecture */
-		*(int*)ldest = *(int*)lsrc; ldest[3]=0;
-#endif
+		memcpy(ldest, lsrc, 3);
 		lsrc += 3; ldest += 4;
 	}
 	static int ProcessBlockSize(void) {
