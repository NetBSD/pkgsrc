$NetBSD: patch-src_dither.c,v 1.1 2024/02/16 08:24:33 nia Exp $

Avoid use of reserved _t name, helps build on SunOS.

--- src/dither.c.orig	2023-10-17 12:24:39.000000000 +0000
+++ src/dither.c
@@ -58,20 +58,20 @@ void pl_generate_bayer_matrix(float *dat
 #define MAX_SIZE (1 << MAX_SIZEB)
 #define MAX_SIZE2 (MAX_SIZE * MAX_SIZE)
 
-typedef uint_fast32_t index_t;
+typedef uint_fast32_t placebo_index_t;
 
-#define WRAP_SIZE2(k, x) ((index_t)((index_t)(x) & ((k)->size2 - 1)))
-#define XY(k, x, y) ((index_t)(((x) | ((y) << (k)->sizeb))))
+#define WRAP_SIZE2(k, x) ((placebo_index_t)((placebo_index_t)(x) & ((k)->size2 - 1)))
+#define XY(k, x, y) ((placebo_index_t)(((x) | ((y) << (k)->sizeb))))
 
 struct ctx {
     unsigned int sizeb, size, size2;
     unsigned int gauss_radius;
     unsigned int gauss_middle;
     uint64_t gauss[MAX_SIZE2];
-    index_t randomat[MAX_SIZE2];
+    placebo_index_t randomat[MAX_SIZE2];
     bool calcmat[MAX_SIZE2];
     uint64_t gaussmat[MAX_SIZE2];
-    index_t unimat[MAX_SIZE2];
+    placebo_index_t unimat[MAX_SIZE2];
 };
 
 static void makegauss(struct ctx *k, unsigned int sizeb)
@@ -88,13 +88,13 @@ static void makegauss(struct ctx *k, uns
     unsigned int gauss_size = k->gauss_radius * 2 + 1;
     unsigned int gauss_size2 = gauss_size * gauss_size;
 
-    for (index_t c = 0; c < k->size2; c++)
+    for (placebo_index_t c = 0; c < k->size2; c++)
         k->gauss[c] = 0;
 
     double sigma = -log(1.5 / (double) UINT64_MAX * gauss_size2) / k->gauss_radius;
 
-    for (index_t gy = 0; gy <= k->gauss_radius; gy++) {
-        for (index_t gx = 0; gx <= gy; gx++) {
+    for (placebo_index_t gy = 0; gy <= k->gauss_radius; gy++) {
+        for (placebo_index_t gx = 0; gx <= gy; gx++) {
             int cx = (int)gx - k->gauss_radius;
             int cy = (int)gy - k->gauss_radius;
             int sq = cx * cx + cy * cy;
@@ -113,7 +113,7 @@ static void makegauss(struct ctx *k, uns
 
 #ifndef NDEBUG
     uint64_t total = 0;
-    for (index_t c = 0; c < k->size2; c++) {
+    for (placebo_index_t c = 0; c < k->size2; c++) {
         uint64_t oldtotal = total;
         total += k->gauss[c];
         assert(total >= oldtotal);
@@ -121,7 +121,7 @@ static void makegauss(struct ctx *k, uns
 #endif
 }
 
-static void setbit(struct ctx *k, index_t c)
+static void setbit(struct ctx *k, placebo_index_t c)
 {
     if (k->calcmat[c])
         return;
@@ -137,12 +137,12 @@ static void setbit(struct ctx *k, index_
         *m++ += *g++;
 }
 
-static index_t getmin(struct ctx *k)
+static placebo_index_t getmin(struct ctx *k)
 {
     uint64_t min = UINT64_MAX;
-    index_t resnum = 0;
+    placebo_index_t resnum = 0;
     unsigned int size2 = k->size2;
-    for (index_t c = 0; c < size2; c++) {
+    for (placebo_index_t c = 0; c < size2; c++) {
         if (k->calcmat[c])
             continue;
         uint64_t total = k->gaussmat[c];
@@ -165,8 +165,8 @@ static index_t getmin(struct ctx *k)
 static void makeuniform(struct ctx *k)
 {
     unsigned int size2 = k->size2;
-    for (index_t c = 0; c < size2; c++) {
-        index_t r = getmin(k);
+    for (placebo_index_t c = 0; c < size2; c++) {
+        placebo_index_t r = getmin(k);
         setbit(k, r);
         k->unimat[r] = c;
     }
@@ -182,8 +182,8 @@ void pl_generate_blue_noise(float *data,
     makegauss(k, shift);
     makeuniform(k);
     float invscale = k->size2;
-    for(index_t y = 0; y < k->size; y++) {
-        for(index_t x = 0; x < k->size; x++)
+    for(placebo_index_t y = 0; y < k->size; y++) {
+        for(placebo_index_t x = 0; x < k->size; x++)
             data[x + y * k->size] = k->unimat[XY(k, x, y)] / invscale;
     }
     pl_free(k);
