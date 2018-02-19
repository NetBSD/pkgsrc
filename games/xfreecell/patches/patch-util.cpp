$NetBSD: patch-util.cpp,v 1.1 2018/02/19 09:51:48 he Exp $

--- util.cpp.orig	1999-03-27 20:17:13.000000000 +0000
+++ util.cpp
@@ -10,9 +10,9 @@
 #include "suit.bm"
 #include "spade_lg.bm"
 
-static void draw(const char*, int, int, int, int, char*);
-static void draw180(const char*, int, int, int, int, char*);
-static void drawBox(int, int, int, int, char*);
+static void draw(unsigned const char*, int, int, int, int, unsigned char*);
+static void draw180(unsigned const char*, int, int, int, int, unsigned char*);
+static void drawBox(int, int, int, int, unsigned char*);
 
 unsigned long getColor(Display *dpy, const char* name)
 {
@@ -39,7 +39,7 @@ SuitColor suitColor(Suit s)
 
 // bitmap
 
-const char* faces[4][3] = {
+const unsigned char* faces[4][3] = {
   {jack_h_bits, queen_h_bits, king_h_bits},
   {jack_d_bits, queen_d_bits, king_d_bits},
   {jack_c_bits, queen_c_bits, king_c_bits},
@@ -78,24 +78,24 @@ static const unsigned char reverseByte[0
   0x0f, 0x8f, 0x4f, 0xcf, 0x2f, 0xaf, 0x6f, 0xef,
   0x1f, 0x9f, 0x5f, 0xdf, 0x3f, 0xbf, 0x7f, 0xff
 };
-static const char* small_suit[4] = {
+static unsigned const char* small_suit[4] = {
   heart_sm_bits, diamond_sm_bits, club_sm_bits, spade_sm_bits};
 static const int small_suit_width[4] = {
   heart_sm_width, diamond_sm_width, club_sm_width, spade_sm_width};
 static const int small_suit_height[4] = {
   heart_sm_height, diamond_sm_height, club_sm_height, spade_sm_height};
-static const char* main_suit[4] = {
+static unsigned const char* main_suit[4] = {
   heart_bits, diamond_bits, club_bits, spade_bits};
 static const int suit_width[4] = {
   heart_width, diamond_width, club_width, spade_width};
 static const int suit_height[4] = {
   heart_height, diamond_height, club_height, spade_height};
 
-void makeBitmap(Suit s, int v, char * bitmap)
+void makeBitmap(Suit s, int v, unsigned char * bitmap)
 {
   memset(bitmap, 0, bmWidth*(cardHeight-2)); // erase
   if (v <= 9) {
-    const char* b = main_suit[s];
+    const unsigned char* b = main_suit[s];
     int w = suit_width[s];
     int h = suit_height[s];
     if (s == Spade && v == 0) { // ace of spades
@@ -156,9 +156,9 @@ void makeBitmap(Suit s, int v, char * bi
   draw180(small_suit[s], x, y, w, h, bitmap);
 }
 
-void makeOneSymbolBitmap(Suit s, char* bitmap)
+void makeOneSymbolBitmap(Suit s, unsigned char* bitmap)
 {
-    const char* b = main_suit[s];
+    unsigned const char* b = main_suit[s];
     int w = suit_width[s];
     int h = suit_height[s];
     
@@ -166,11 +166,11 @@ void makeOneSymbolBitmap(Suit s, char* b
     draw(b, (cardWidth-2-w)/2, (cardHeight-2-h)/2, w, h, bitmap);
 }
 
-static void draw(const char* from, int x, int y, int w, int h, char* bitmap) {
-  char* to1 = bitmap+y*bmWidth+x/8;
+static void draw(unsigned const char* from, int x, int y, int w, int h, unsigned char* bitmap) {
+  unsigned char* to1 = bitmap+y*bmWidth+x/8;
   int shift = x%8;
   for (int j = 0; j < h; j++) {
-    char* to = to1; to1 += bmWidth;
+    unsigned char* to = to1; to1 += bmWidth;
     char wrap = 0;
     for (int i = 0; i < w; i += 8) {
       unsigned char v = *from++;
@@ -181,13 +181,13 @@ static void draw(const char* from, int x
   }
 }
 
-static void draw180(const char* from, int x, int y, int w, int h, char* bitmap) {
+static void draw180(unsigned const char* from, int x, int y, int w, int h, unsigned char* bitmap) {
   x = cardWidth-3-x;
   y = cardHeight-3-y;
-  char* to1 = bitmap+y*bmWidth+x/8;
+  unsigned char* to1 = bitmap+y*bmWidth+x/8;
   int shift = 7-x%8;
   for (int j = 0; j < h; j++) {
-    char* to = to1; to1 -= bmWidth;
+    unsigned char* to = to1; to1 -= bmWidth;
     char wrap = 0;
     for (int i = 0; i < w; i += 8) {
       unsigned char v = reverseByte[(unsigned char)(*from++)];
@@ -198,14 +198,14 @@ static void draw180(const char* from, in
   }
 }
 
-static void drawBox(int x, int y, int w, int h, char* bitmap) {
-  char* to1 = bitmap+y*bmWidth+x/8;
-  char* to2 = bitmap+y*bmWidth+(x+w-1)/8;
-  char v1 = 1 << (x%8);
-  char v2 = 1 << ((x+w-1)%8);
+static void drawBox(int x, int y, int w, int h, unsigned char* bitmap) {
+  unsigned char* to1 = bitmap+y*bmWidth+x/8;
+  unsigned char* to2 = bitmap+y*bmWidth+(x+w-1)/8;
+  unsigned char v1 = 1 << (x%8);
+  unsigned char v2 = 1 << ((x+w-1)%8);
   *to1 = *(to1+(h-1)*bmWidth) = ~(v1-1);
   *to2 = *(to2+(h-1)*bmWidth) = (v2<<1)-1;
-  for (char* t = to1+1; t < to2; t++) *t = *(t+(h-1)*bmWidth) = 255;
+  for (unsigned char* t = to1+1; t < to2; t++) *t = *(t+(h-1)*bmWidth) = 255;
   for (int j = 2; j < h; j++) {
     to1 += bmWidth; *to1 |= v1;
     to2 += bmWidth; *to2 |= v2;
