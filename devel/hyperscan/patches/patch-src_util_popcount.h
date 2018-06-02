$NetBSD: patch-src_util_popcount.h,v 1.1 2018/06/02 19:13:45 joerg Exp $

--- src/util/popcount.h.orig	2018-06-02 15:16:11.582620623 +0000
+++ src/util/popcount.h
@@ -36,6 +36,7 @@
 #include "ue2common.h"
 #include "util/arch.h"
 
+#ifndef __NetBSD__
 static really_inline
 u32 popcount32(u32 x) {
 #if defined(HAVE_POPCOUNT_INSTR)
@@ -69,6 +70,9 @@ u32 popcount64(u64a x) {
     return popcount32(x >> 32) + popcount32(x);
 #endif
 }
+#else
+#include <strings.h>
+#endif
 
 #endif /* UTIL_POPCOUNT_H_ */
 
