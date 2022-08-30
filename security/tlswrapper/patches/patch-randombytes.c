$NetBSD: patch-randombytes.c,v 1.1 2022/08/30 17:55:31 schmonz Exp $

Apply upstream commit 0cb7bb4 to fall back to /dev/urandom on systems
where getentropy() is not present.

--- randombytes.c.orig	2022-08-14 12:18:16.000000000 +0000
+++ randombytes.c
@@ -1,30 +1,9 @@
-/*
-version 20220222
-*/
-
-#include <unistd.h>
-#ifdef __APPLE__
-#include <sys/random.h>
-#endif
 #include "randombytes.h"
 
-void randombytes(void *xv, long long xlen) {
-
-    long long i;
-    unsigned char *x = (unsigned char *) xv;
-
-    while (xlen > 0) {
-        if (xlen < 256)
-            i = xlen;
-        else
-            i = 256;
+#ifdef randombytes_getentropy
+#include "randombytes.c-01getentropy"
+#endif
 
-        if (getentropy(x, i) == -1) {
-            sleep(1);
-            continue;
-        }
-        x += i;
-        xlen -= i;
-    }
-    __asm__ __volatile__("" : : "r"(xv) : "memory");
-}
+#ifdef randombytes_devurandom
+#include "randombytes.c-02devurandom"
+#endif
