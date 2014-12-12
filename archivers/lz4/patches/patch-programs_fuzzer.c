$NetBSD: patch-programs_fuzzer.c,v 1.3 2014/12/12 11:20:56 fhajny Exp $

Add portable code for ftime for NetBSD.

Based on https://code.google.com/p/lz4/source/detail?r=81.
--- programs/fuzzer.c.orig	2014-11-06 18:39:42.000000000 +0000
+++ programs/fuzzer.c
@@ -30,6 +30,7 @@ Remove Visual warning messages
 #  pragma warning(disable : 4127)        /* disable: C4127: conditional expression is constant */
 #  pragma warning(disable : 4146)        /* disable: C4146: minus unsigned expression */
 #  pragma warning(disable : 4310)        /* disable: C4310: constant char value > 127 */
+#  define BMK_LEGACY_TIMER 1
 #endif
 
 
@@ -38,12 +39,18 @@ Includes
 **************************************/
 #include <stdlib.h>
 #include <stdio.h>      // fgets, sscanf
-#include <sys/timeb.h>  // timeb
 #include <string.h>     // strcmp
 #include "lz4.h"
 #include "lz4hc.h"
 #include "xxhash.h"
 
+// Use ftime() if gettimeofday() is not available on your target
+#if defined(BMK_LEGACY_TIMER)
+#  include <sys/timeb.h>   // timeb, ftime
+#else
+#  include <sys/time.h>    // gettimeofday
+#endif
+
 
 /**************************************
 Basic Types
@@ -99,8 +106,11 @@ static U32 g_time = 0;
 /*********************************************************
   Fuzzer functions
 *********************************************************/
+#if defined(BMK_LEGACY_TIMER)
+
 static U32 FUZ_GetMilliStart(void)
 {
+    // Based on Legacy ftime()
     struct timeb tb;
     U32 nCount;
     ftime( &tb );
@@ -108,6 +118,21 @@ static U32 FUZ_GetMilliStart(void)
     return nCount;
 }
 
+#else
+
+static int FUZ_GetMilliStart()
+{
+  // Based on newer gettimeofday()
+  // Use GetMilliSpan to correct for rollover
+  struct timeval tv;
+  int nCount;
+  gettimeofday(&tv, NULL);
+  nCount = (int) (tv.tv_usec/1000 + (tv.tv_sec & 0xfffff) * 1000);
+  return nCount;
+}
+
+#endif
+
 static U32 FUZ_GetMilliSpan(U32 nTimeStart)
 {
     U32 nCurrent = FUZ_GetMilliStart();
