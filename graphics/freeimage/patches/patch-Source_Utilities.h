$NetBSD: patch-Source_Utilities.h,v 1.1 2020/05/14 16:42:14 nia Exp $

Unbundle image libraries.

--- Source/Utilities.h.orig	2016-04-11 14:15:32.000000000 +0000
+++ Source/Utilities.h
@@ -446,12 +446,12 @@ SwapLong(DWORD *lp) {
 }
  
 inline void
-SwapInt64(UINT64 *arg) {
+SwapInt64(uint64_t *arg) {
 #if defined(_MSC_VER) && _MSC_VER >= 1310
 	*arg = _byteswap_uint64(*arg);
 #else
 	union Swap {
-		UINT64 sv;
+		uint64_t sv;
 		DWORD ul[2];
 	} tmp, result;
 	tmp.sv = *arg;
