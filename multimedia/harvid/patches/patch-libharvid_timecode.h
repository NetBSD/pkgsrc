$NetBSD: patch-libharvid_timecode.h,v 1.1 2019/12/02 13:42:00 nia Exp $

Remove redefinition of stdint types

--- libharvid/timecode.h.orig	2018-11-30 22:30:41.000000000 +0000
+++ libharvid/timecode.h
@@ -23,18 +23,6 @@
 #include <inttypes.h>
 #include <stdint.h>
 
-#if (!defined int32_t && !defined __int8_t_defined && !defined _INT32_T)
-typedef int int32_t;
-#endif
-
-#if (!defined int64_t && !defined __int8_t_defined && !defined _UINT64_T)
-#  if __WORDSIZE == 64
-typedef long int int64_t;
-#else
-typedef long long int int64_t;
-#endif
-#endif
-
 /**
  * classical timecode
  */
