$NetBSD: patch-sql_join__optimizer_bit__utils.h,v 1.1 2021/06/27 06:41:55 nia Exp $

NetBSD has no ffsll, but GCC does.

--- sql/join_optimizer/bit_utils.h.orig	2021-03-22 08:44:50.000000000 +0000
+++ sql/join_optimizer/bit_utils.h
@@ -82,6 +82,8 @@ static inline size_t FindLowestBitSet(ui
   size_t idx;
   asm("bsfq %1,%q0" : "=r"(idx) : "rm"(x));
   return idx;
+#elif defined(__GNUC__) && !defined(HAVE_FFSLL)
+  return static_cast<unsigned>(__builtin_ffsll(x)) - 1u;
 #else
   // The cast to unsigned at least gets rid of the sign extension.
   return static_cast<unsigned>(ffsll(x)) - 1u;
