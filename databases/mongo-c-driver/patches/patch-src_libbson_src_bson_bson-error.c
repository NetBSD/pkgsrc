$NetBSD: patch-src_libbson_src_bson_bson-error.c,v 1.1 2023/08/27 08:51:08 adam Exp $

Fix build on NetBSD.

--- src/libbson/src/bson/bson-error.c.orig	2023-08-27 04:27:34.243073551 +0000
+++ src/libbson/src/bson/bson-error.c
@@ -126,6 +126,10 @@ bson_strerror_r (int err_code,          
    // required) by the POSIX spec (see:
    // https://pubs.opengroup.org/onlinepubs/9699919799/functions/strerror.html#tag_16_574_08).
    (void) strerror_r (err_code, buf, buflen);
+#elif defined(__NetBSD__)
+   if (strerror_r(err_code, buf, buflen) == 0) {
+     ret = buf;
+   }
 #elif defined(_XOPEN_SOURCE) && _XOPEN_SOURCE >= 700
    // The behavior (of `strerror_l`) is undefined if the locale argument to
    // `strerror_l()` is the special locale object LC_GLOBAL_LOCALE or is not a
