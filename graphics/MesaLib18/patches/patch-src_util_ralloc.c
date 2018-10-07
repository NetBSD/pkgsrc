$NetBSD: patch-src_util_ralloc.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

FreeBSD reported atexit bug for 10.6:
https://bugs.freedesktop.org/show_bug.cgi?id=91869

* Fix exit time segfault of qt5 application with modular xorg
* Provide compat strnlen for older Darwin.

--- src/util/ralloc.c.orig	2017-05-10 14:13:58.000000000 +0000
+++ src/util/ralloc.c
@@ -368,7 +368,14 @@ ralloc_strndup(const void *ctx, const ch
    if (unlikely(str == NULL))
       return NULL;
 
+#if (defined(__APPLE__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__-0 < 1070)
+   for (n = 0; n < max; n++, str++) {
+     if (!*str)
+       break;
+   }
+#else
    n = strnlen(str, max);
+#endif
    ptr = ralloc_array(ctx, char, n + 1);
    memcpy(ptr, str, n);
    ptr[n] = '\0';
