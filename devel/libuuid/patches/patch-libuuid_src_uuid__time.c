$NetBSD: patch-libuuid_src_uuid__time.c,v 1.1 2025/12/18 21:11:16 maya Exp $

Pull upstream commit to fix build on Darwin
https://github.com/util-linux/util-linux/commit/e47c6f751a7ef87640c61316ada774e8e9cc6b07

Weak aliases are not supported by clang on Darwin.
Instead this fix uses inline asm to make `_uuid_time` an alias to
`___uuid_time`

--- libuuid/src/uuid_time.c.orig	2025-12-18 20:52:14.039965440 +0000
+++ libuuid/src/uuid_time.c
@@ -85,6 +85,10 @@ time_t __uuid_time(const uuid_t uu, stru
 }
 #if defined(__USE_TIME_BITS64) && defined(__GLIBC__)
 extern time_t uuid_time64(const uuid_t uu, struct timeval *ret_tv) __attribute__((weak, alias("__uuid_time")));
+#elif defined(__clang__) && defined(__APPLE__)
+__asm__(".globl _uuid_time");
+__asm__(".set _uuid_time, ___uuid_time");
+extern time_t uuid_time(const uuid_t uu, struct timeval *ret_tv);
 #else
 extern time_t uuid_time(const uuid_t uu, struct timeval *ret_tv) __attribute__((weak, alias("__uuid_time")));
 #endif
