$NetBSD: patch-crypto_rand_rand__unix.c,v 1.1 2020/04/30 11:21:57 nia Exp $

Fix usage of KERN_ARND on NetBSD.

First, actually include the correct headers.
Second, disable a hack for old FreeBSD versions (just in case it gets used).
Third, ensure that we don't ever request more than 256 bytes (just in case).

--- crypto/rand/rand_unix.c.orig	2020-04-21 12:22:39.000000000 +0000
+++ crypto/rand/rand_unix.c
@@ -26,12 +26,12 @@
 #  include <sys/utsname.h>
 # endif
 #endif
-#if defined(__FreeBSD__) && !defined(OPENSSL_SYS_UEFI)
+#if (defined(__FreeBSD__) || defined(__NetBSD__)) && !defined(OPENSSL_SYS_UEFI)
 # include <sys/types.h>
 # include <sys/sysctl.h>
 # include <sys/param.h>
 #endif
-#if defined(__OpenBSD__) || defined(__NetBSD__)
+#if defined(__OpenBSD__)
 # include <sys/param.h>
 #endif
 
@@ -247,10 +247,12 @@ static ssize_t sysctl_random(char *buf, 
      * when the sysctl returns long and we want to request something not a
      * multiple of longs, which should never be the case.
      */
+#if   defined(__FreeBSD__)
     if (!ossl_assert(buflen % sizeof(long) == 0)) {
         errno = EINVAL;
         return -1;
     }
+#endif
 
     /*
      * On NetBSD before 4.0 KERN_ARND was an alias for KERN_URND, and only
@@ -268,7 +270,7 @@ static ssize_t sysctl_random(char *buf, 
     mib[1] = KERN_ARND;
 
     do {
-        len = buflen;
+        len = buflen > 256 ? 256 : buflen;
         if (sysctl(mib, 2, buf, &len, NULL, 0) == -1)
             return done > 0 ? done : -1;
         done += len;
