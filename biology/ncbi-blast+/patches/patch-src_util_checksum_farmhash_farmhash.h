$NetBSD: patch-src_util_checksum_farmhash_farmhash.h,v 1.1 2019/01/07 15:00:11 bacon Exp $

# __GNUC__ does not imply location of endian.h.  Check for BSD first.

--- src/util/checksum/farmhash/farmhash.h.orig	2018-09-26 12:38:06.000000000 +0000
+++ src/util/checksum/farmhash/farmhash.h
@@ -305,15 +305,18 @@ inline uint128_t Fingerprint128(const St
   #if !defined(FARMHASH_BIG_ENDIAN)
     #define FARMHASH_BIG_ENDIAN
   #endif
-#elif defined(__linux__) || defined(__CYGWIN__) || defined( __GNUC__ ) || defined( __GNU_LIBRARY__ )
-  #include <endian.h> // libc6-dev, GLIBC
+#elif defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__s390x__)
+  #include <sys/endian.h>
   #if BYTE_ORDER == BIG_ENDIAN
     #if !defined(FARMHASH_BIG_ENDIAN)
       #define FARMHASH_BIG_ENDIAN
     #endif
   #endif
-#elif defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__s390x__)
-  #include <sys/endian.h>
+// __GNUC__ actually does not imply the location of endian.h.  It could
+// be set on any system running GCC.  I'm wondering why this was added
+// Working around breakage for BSD systems by checking for BSD first.
+#elif defined(__linux__) || defined(__CYGWIN__) || defined( __GNUC__ ) || defined( __GNU_LIBRARY__ )
+  #include <endian.h> // libc6-dev, GLIBC
   #if BYTE_ORDER == BIG_ENDIAN
     #if !defined(FARMHASH_BIG_ENDIAN)
       #define FARMHASH_BIG_ENDIAN
