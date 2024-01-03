$NetBSD: patch-include_libsais.h,v 1.1 2024/01/03 08:16:36 nros Exp $

* Avoid redefinition of bswap16 on NetBSD

--- include/libsais.h.orig	2024-01-03 08:05:47.672459407 +0000
+++ include/libsais.h
@@ -4629,7 +4629,7 @@ static void libsais_unbwt_decode_1(u8 * 
             } while (bucket2[c0] <= p0);
         }
         p0 = P[p0];
-        U0[i] = bswap16(c0);
+        U0[i] = bzip3_beton16(c0);
     }
 
     *i0 = p0;
@@ -4651,7 +4651,7 @@ static void libsais_unbwt_decode_2(u8 * 
             } while (bucket2[c0] <= p0);
         }
         p0 = P[p0];
-        U0[i] = bswap16(c0);
+        U0[i] = bzip3_beton16(c0);
         u16 c1 = fastbits[p1 >> shift];
         if (bucket2[c1] <= p1) {
             do {
@@ -4659,7 +4659,7 @@ static void libsais_unbwt_decode_2(u8 * 
             } while (bucket2[c1] <= p1);
         }
         p1 = P[p1];
-        U1[i] = bswap16(c1);
+        U1[i] = bzip3_beton16(c1);
     }
 
     *i0 = p0;
@@ -4683,7 +4683,7 @@ static void libsais_unbwt_decode_3(u8 * 
             } while (bucket2[c0] <= p0);
         }
         p0 = P[p0];
-        U0[i] = bswap16(c0);
+        U0[i] = bzip3_beton16(c0);
         u16 c1 = fastbits[p1 >> shift];
         if (bucket2[c1] <= p1) {
             do {
@@ -4691,7 +4691,7 @@ static void libsais_unbwt_decode_3(u8 * 
             } while (bucket2[c1] <= p1);
         }
         p1 = P[p1];
-        U1[i] = bswap16(c1);
+        U1[i] = bzip3_beton16(c1);
         u16 c2 = fastbits[p2 >> shift];
         if (bucket2[c2] <= p2) {
             do {
@@ -4699,7 +4699,7 @@ static void libsais_unbwt_decode_3(u8 * 
             } while (bucket2[c2] <= p2);
         }
         p2 = P[p2];
-        U2[i] = bswap16(c2);
+        U2[i] = bzip3_beton16(c2);
     }
 
     *i0 = p0;
@@ -4725,7 +4725,7 @@ static void libsais_unbwt_decode_4(u8 * 
             } while (bucket2[c0] <= p0);
         }
         p0 = P[p0];
-        U0[i] = bswap16(c0);
+        U0[i] = bzip3_beton16(c0);
         u16 c1 = fastbits[p1 >> shift];
         if (bucket2[c1] <= p1) {
             do {
@@ -4733,7 +4733,7 @@ static void libsais_unbwt_decode_4(u8 * 
             } while (bucket2[c1] <= p1);
         }
         p1 = P[p1];
-        U1[i] = bswap16(c1);
+        U1[i] = bzip3_beton16(c1);
         u16 c2 = fastbits[p2 >> shift];
         if (bucket2[c2] <= p2) {
             do {
@@ -4741,7 +4741,7 @@ static void libsais_unbwt_decode_4(u8 * 
             } while (bucket2[c2] <= p2);
         }
         p2 = P[p2];
-        U2[i] = bswap16(c2);
+        U2[i] = bzip3_beton16(c2);
         u16 c3 = fastbits[p3 >> shift];
         if (bucket2[c3] <= p3) {
             do {
@@ -4749,7 +4749,7 @@ static void libsais_unbwt_decode_4(u8 * 
             } while (bucket2[c3] <= p3);
         }
         p3 = P[p3];
-        U3[i] = bswap16(c3);
+        U3[i] = bzip3_beton16(c3);
     }
 
     *i0 = p0;
@@ -4778,7 +4778,7 @@ static void libsais_unbwt_decode_5(u8 * 
             } while (bucket2[c0] <= p0);
         }
         p0 = P[p0];
-        U0[i] = bswap16(c0);
+        U0[i] = bzip3_beton16(c0);
         u16 c1 = fastbits[p1 >> shift];
         if (bucket2[c1] <= p1) {
             do {
@@ -4786,7 +4786,7 @@ static void libsais_unbwt_decode_5(u8 * 
             } while (bucket2[c1] <= p1);
         }
         p1 = P[p1];
-        U1[i] = bswap16(c1);
+        U1[i] = bzip3_beton16(c1);
         u16 c2 = fastbits[p2 >> shift];
         if (bucket2[c2] <= p2) {
             do {
@@ -4794,7 +4794,7 @@ static void libsais_unbwt_decode_5(u8 * 
             } while (bucket2[c2] <= p2);
         }
         p2 = P[p2];
-        U2[i] = bswap16(c2);
+        U2[i] = bzip3_beton16(c2);
         u16 c3 = fastbits[p3 >> shift];
         if (bucket2[c3] <= p3) {
             do {
@@ -4802,7 +4802,7 @@ static void libsais_unbwt_decode_5(u8 * 
             } while (bucket2[c3] <= p3);
         }
         p3 = P[p3];
-        U3[i] = bswap16(c3);
+        U3[i] = bzip3_beton16(c3);
         u16 c4 = fastbits[p4 >> shift];
         if (bucket2[c4] <= p4) {
             do {
@@ -4810,7 +4810,7 @@ static void libsais_unbwt_decode_5(u8 * 
             } while (bucket2[c4] <= p4);
         }
         p4 = P[p4];
-        U4[i] = bswap16(c4);
+        U4[i] = bzip3_beton16(c4);
     }
 
     *i0 = p0;
@@ -4841,7 +4841,7 @@ static void libsais_unbwt_decode_6(u8 * 
             } while (bucket2[c0] <= p0);
         }
         p0 = P[p0];
-        U0[i] = bswap16(c0);
+        U0[i] = bzip3_beton16(c0);
         u16 c1 = fastbits[p1 >> shift];
         if (bucket2[c1] <= p1) {
             do {
@@ -4849,7 +4849,7 @@ static void libsais_unbwt_decode_6(u8 * 
             } while (bucket2[c1] <= p1);
         }
         p1 = P[p1];
-        U1[i] = bswap16(c1);
+        U1[i] = bzip3_beton16(c1);
         u16 c2 = fastbits[p2 >> shift];
         if (bucket2[c2] <= p2) {
             do {
@@ -4857,7 +4857,7 @@ static void libsais_unbwt_decode_6(u8 * 
             } while (bucket2[c2] <= p2);
         }
         p2 = P[p2];
-        U2[i] = bswap16(c2);
+        U2[i] = bzip3_beton16(c2);
         u16 c3 = fastbits[p3 >> shift];
         if (bucket2[c3] <= p3) {
             do {
@@ -4865,7 +4865,7 @@ static void libsais_unbwt_decode_6(u8 * 
             } while (bucket2[c3] <= p3);
         }
         p3 = P[p3];
-        U3[i] = bswap16(c3);
+        U3[i] = bzip3_beton16(c3);
         u16 c4 = fastbits[p4 >> shift];
         if (bucket2[c4] <= p4) {
             do {
@@ -4873,7 +4873,7 @@ static void libsais_unbwt_decode_6(u8 * 
             } while (bucket2[c4] <= p4);
         }
         p4 = P[p4];
-        U4[i] = bswap16(c4);
+        U4[i] = bzip3_beton16(c4);
         u16 c5 = fastbits[p5 >> shift];
         if (bucket2[c5] <= p5) {
             do {
@@ -4881,7 +4881,7 @@ static void libsais_unbwt_decode_6(u8 * 
             } while (bucket2[c5] <= p5);
         }
         p5 = P[p5];
-        U5[i] = bswap16(c5);
+        U5[i] = bzip3_beton16(c5);
     }
 
     *i0 = p0;
@@ -4914,7 +4914,7 @@ static void libsais_unbwt_decode_7(u8 * 
             } while (bucket2[c0] <= p0);
         }
         p0 = P[p0];
-        U0[i] = bswap16(c0);
+        U0[i] = bzip3_beton16(c0);
         u16 c1 = fastbits[p1 >> shift];
         if (bucket2[c1] <= p1) {
             do {
@@ -4922,7 +4922,7 @@ static void libsais_unbwt_decode_7(u8 * 
             } while (bucket2[c1] <= p1);
         }
         p1 = P[p1];
-        U1[i] = bswap16(c1);
+        U1[i] = bzip3_beton16(c1);
         u16 c2 = fastbits[p2 >> shift];
         if (bucket2[c2] <= p2) {
             do {
@@ -4930,7 +4930,7 @@ static void libsais_unbwt_decode_7(u8 * 
             } while (bucket2[c2] <= p2);
         }
         p2 = P[p2];
-        U2[i] = bswap16(c2);
+        U2[i] = bzip3_beton16(c2);
         u16 c3 = fastbits[p3 >> shift];
         if (bucket2[c3] <= p3) {
             do {
@@ -4938,7 +4938,7 @@ static void libsais_unbwt_decode_7(u8 * 
             } while (bucket2[c3] <= p3);
         }
         p3 = P[p3];
-        U3[i] = bswap16(c3);
+        U3[i] = bzip3_beton16(c3);
         u16 c4 = fastbits[p4 >> shift];
         if (bucket2[c4] <= p4) {
             do {
@@ -4946,7 +4946,7 @@ static void libsais_unbwt_decode_7(u8 * 
             } while (bucket2[c4] <= p4);
         }
         p4 = P[p4];
-        U4[i] = bswap16(c4);
+        U4[i] = bzip3_beton16(c4);
         u16 c5 = fastbits[p5 >> shift];
         if (bucket2[c5] <= p5) {
             do {
@@ -4954,7 +4954,7 @@ static void libsais_unbwt_decode_7(u8 * 
             } while (bucket2[c5] <= p5);
         }
         p5 = P[p5];
-        U5[i] = bswap16(c5);
+        U5[i] = bzip3_beton16(c5);
         u16 c6 = fastbits[p6 >> shift];
         if (bucket2[c6] <= p6) {
             do {
@@ -4962,7 +4962,7 @@ static void libsais_unbwt_decode_7(u8 * 
             } while (bucket2[c6] <= p6);
         }
         p6 = P[p6];
-        U6[i] = bswap16(c6);
+        U6[i] = bzip3_beton16(c6);
     }
 
     *i0 = p0;
@@ -4997,7 +4997,7 @@ static void libsais_unbwt_decode_8(u8 * 
             } while (bucket2[c0] <= p0);
         }
         p0 = P[p0];
-        U0[i] = bswap16(c0);
+        U0[i] = bzip3_beton16(c0);
         u16 c1 = fastbits[p1 >> shift];
         if (bucket2[c1] <= p1) {
             do {
@@ -5005,7 +5005,7 @@ static void libsais_unbwt_decode_8(u8 * 
             } while (bucket2[c1] <= p1);
         }
         p1 = P[p1];
-        U1[i] = bswap16(c1);
+        U1[i] = bzip3_beton16(c1);
         u16 c2 = fastbits[p2 >> shift];
         if (bucket2[c2] <= p2) {
             do {
@@ -5013,7 +5013,7 @@ static void libsais_unbwt_decode_8(u8 * 
             } while (bucket2[c2] <= p2);
         }
         p2 = P[p2];
-        U2[i] = bswap16(c2);
+        U2[i] = bzip3_beton16(c2);
         u16 c3 = fastbits[p3 >> shift];
         if (bucket2[c3] <= p3) {
             do {
@@ -5021,7 +5021,7 @@ static void libsais_unbwt_decode_8(u8 * 
             } while (bucket2[c3] <= p3);
         }
         p3 = P[p3];
-        U3[i] = bswap16(c3);
+        U3[i] = bzip3_beton16(c3);
         u16 c4 = fastbits[p4 >> shift];
         if (bucket2[c4] <= p4) {
             do {
@@ -5029,7 +5029,7 @@ static void libsais_unbwt_decode_8(u8 * 
             } while (bucket2[c4] <= p4);
         }
         p4 = P[p4];
-        U4[i] = bswap16(c4);
+        U4[i] = bzip3_beton16(c4);
         u16 c5 = fastbits[p5 >> shift];
         if (bucket2[c5] <= p5) {
             do {
@@ -5037,7 +5037,7 @@ static void libsais_unbwt_decode_8(u8 * 
             } while (bucket2[c5] <= p5);
         }
         p5 = P[p5];
-        U5[i] = bswap16(c5);
+        U5[i] = bzip3_beton16(c5);
         u16 c6 = fastbits[p6 >> shift];
         if (bucket2[c6] <= p6) {
             do {
@@ -5045,7 +5045,7 @@ static void libsais_unbwt_decode_8(u8 * 
             } while (bucket2[c6] <= p6);
         }
         p6 = P[p6];
-        U6[i] = bswap16(c6);
+        U6[i] = bzip3_beton16(c6);
         u16 c7 = fastbits[p7 >> shift];
         if (bucket2[c7] <= p7) {
             do {
@@ -5053,7 +5053,7 @@ static void libsais_unbwt_decode_8(u8 * 
             } while (bucket2[c7] <= p7);
         }
         p7 = P[p7];
-        U7[i] = bswap16(c7);
+        U7[i] = bzip3_beton16(c7);
     }
 
     *i0 = p0;
