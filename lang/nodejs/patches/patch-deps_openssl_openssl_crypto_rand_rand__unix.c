$NetBSD: patch-deps_openssl_openssl_crypto_rand_rand__unix.c,v 1.1 2019/07/02 17:09:25 jperkin Exp $

Don't try to automatically call getentropy(3C) on SunOS, it fails if
built on a platform that doesn't have it.

--- deps/openssl/openssl/crypto/rand/rand_unix.c.orig	2019-05-28 21:32:16.000000000 +0000
+++ deps/openssl/openssl/crypto/rand/rand_unix.c
@@ -301,7 +301,7 @@ static ssize_t syscall_random(void *buf,
      * - Linux since 3.17 with glibc 2.25
      * - FreeBSD since 12.0 (1200061)
      */
-#  if defined(__GNUC__) && __GNUC__>=2 && defined(__ELF__) && !defined(__hpux)
+#  if defined(__GNUC__) && __GNUC__>=2 && defined(__ELF__) && !defined(__hpux) && !defined(__sun)
     extern int getentropy(void *buffer, size_t length) __attribute__((weak));
 
     if (getentropy != NULL)
