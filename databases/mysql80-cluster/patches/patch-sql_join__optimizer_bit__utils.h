$NetBSD: patch-sql_join__optimizer_bit__utils.h,v 1.1 2024/08/05 01:24:00 jnemeth Exp $

--- sql/join_optimizer/bit_utils.h.orig	2022-03-23 13:49:36.000000000 +0000
+++ sql/join_optimizer/bit_utils.h
@@ -82,6 +82,8 @@ inline size_t FindLowestBitSet(uint64_t 
   size_t idx;
   asm("bsfq %1,%q0" : "=r"(idx) : "rm"(x));
   return idx;
+#elif defined(__GNUC__) && !defined(HAVE_FFSLL)
+  return static_cast<unsigned>(__builtin_ffsll(x)) - 1u;
 #else
   // The cast to unsigned at least gets rid of the sign extension.
   return static_cast<unsigned>(ffsll(x)) - 1u;
