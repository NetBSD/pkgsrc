$NetBSD: patch-contrib_t1ha_t1ha__bits.h,v 1.1 2018/05/16 16:49:44 fhajny Exp $

Backport SunOS fix.

https://github.com/vstakhov/rspamd/commit/7f596814c14a5844d49c50cad68df568e6417793

--- contrib/t1ha/t1ha_bits.h.orig	2018-05-01 15:52:02.000000000 +0000
+++ contrib/t1ha/t1ha_bits.h
@@ -390,7 +390,7 @@ static __always_inline uint16_t fetch16_
 #endif /* fetch16_le */
 
 #if T1HA_USE_FAST_ONESHOT_READ && UNALIGNED_OK && defined(PAGESIZE) &&         \
-    PAGESIZE > 0 && !defined(__SANITIZE_ADDRESS__)
+    !defined(__SANITIZE_ADDRESS__) && !defined(__sun)
 #define can_read_underside(ptr, size)                                          \
   ((size) <= sizeof(uintptr_t) && ((PAGESIZE - (size)) & (uintptr_t)(ptr)) != 0)
 #endif /* can_fast_read */
