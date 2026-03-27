$NetBSD: patch-src_common_pa__converters.c,v 1.1 2026/03/27 18:43:51 tnn Exp $

clang complains:
      conversion from 'int' to 'float' changes value from 2147483647 to
      2147483648 [-Werror,-Wimplicit-const-int-float-conversion]

In the expressions, 0x7FFFFFFF gets implicitly converted and rounded
to (float)0x80000000 which seems not what the code intends here.
In order to avoid clipping it may be more correct to use 0x7FFFFF80 which
is the nearest smaller integer that converts exactly into an IEEE 32-bit float.
That said; in order to not change existing behaviour just add explicit casts.

--- src/common/pa_converters.c.orig	2026-03-27 18:10:20.809295041 +0000
+++ src/common/pa_converters.c
@@ -344,10 +344,10 @@ static void Float32_To_Int32(
     {
         /* REVIEW */
 #ifdef PA_USE_C99_LRINTF
-        float scaled = *src * 0x7FFFFFFF;
+        float scaled = *src * (float)0x7FFFFFFF;
         *dest = lrintf(scaled-0.5f);
 #else
-        double scaled = *src * 0x7FFFFFFF;
+        double scaled = *src * (double)0x7FFFFFFF;
         *dest = (PaInt32) scaled;
 #endif
 
@@ -400,11 +400,11 @@ static void Float32_To_Int32_Clip(
     {
         /* REVIEW */
 #ifdef PA_USE_C99_LRINTF
-        float scaled = *src * 0x7FFFFFFF;
+        float scaled = *src * (float)0x7FFFFFFF;
         PA_CLIP_( scaled, -2147483648.f, 2147483647.f  );
         *dest = lrintf(scaled-0.5f);
 #else
-        double scaled = *src * 0x7FFFFFFF;
+        double scaled = *src * (double)0x7FFFFFFF;
         PA_CLIP_( scaled, -2147483648., 2147483647.  );
         *dest = (PaInt32) scaled;
 #endif
@@ -532,7 +532,7 @@ static void Float32_To_Int24_Clip(
     while( count-- )
     {
         /* convert to 32 bit and drop the low 8 bits */
-        double scaled = *src * 0x7FFFFFFF;
+        double scaled = *src * (double)0x7FFFFFFF;
         PA_CLIP_( scaled, -2147483648., 2147483647.  );
         temp = (PaInt32) scaled;
 
