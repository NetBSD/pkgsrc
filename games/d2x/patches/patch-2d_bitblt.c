$NetBSD: patch-2d_bitblt.c,v 1.1 2012/11/23 12:33:45 joerg Exp $

--- 2d/bitblt.c.orig	2012-11-21 16:32:42.000000000 +0000
+++ 2d/bitblt.c
@@ -159,7 +159,7 @@ void gr_linear_movsd( ubyte * source, ub
 
 #elif !defined(NO_ASM) && defined(__GNUC__)
 
-inline void gr_linear_movsd(ubyte *src, ubyte *dest, unsigned int num_pixels) {
+static inline void gr_linear_movsd(ubyte *src, ubyte *dest, unsigned int num_pixels) {
 	int dummy[3];
  __asm__ __volatile__ (
 " cld;"
@@ -185,7 +185,7 @@ inline void gr_linear_movsd(ubyte *src, 
 
 #elif !defined(NO_ASM) && defined(_MSC_VER)
 
-__inline void gr_linear_movsd(ubyte *src, ubyte *dest, unsigned int num_pixels)
+static __inline void gr_linear_movsd(ubyte *src, ubyte *dest, unsigned int num_pixels)
 {
  __asm {
    mov esi, [src]
@@ -297,7 +297,7 @@ static inline void gr_linear_rep_movsdm(
 
 #elif !defined(NO_ASM) && defined(_MSC_VER)
 
-__inline void gr_linear_rep_movsdm(ubyte * src, ubyte * dest, unsigned int num_pixels )
+static __inline void gr_linear_rep_movsdm(ubyte * src, ubyte * dest, unsigned int num_pixels )
 {
  __asm {
   nextpixel:
@@ -380,7 +380,7 @@ static inline void gr_linear_rep_movsdm_
 
 #elif !defined(NO_ASM) && defined(_MSC_VER)
 
-__inline void gr_linear_rep_movsdm_faded(void * src, void * dest, unsigned int num_pixels, ubyte fade_value )
+static __inline void gr_linear_rep_movsdm_faded(void * src, void * dest, unsigned int num_pixels, ubyte fade_value )
 {
  __asm {
   mov esi, [src]
@@ -481,7 +481,7 @@ static inline void gr_linear_rep_movsd_2
 
 #elif !defined(NO_ASM) && defined(_MSC_VER)
 
-__inline void gr_linear_rep_movsd_2x(ubyte * src, ubyte * dest, unsigned int num_dest_pixels )
+static __inline void gr_linear_rep_movsd_2x(ubyte * src, ubyte * dest, unsigned int num_dest_pixels )
 {
  __asm {
   mov esi, [src]
@@ -2113,7 +2113,7 @@ void gr_bm_ubitbltm(int w, int h, int dx
 
 // rescalling bitmaps, 10/14/99 Jan Bobrowski jb@wizard.ae.krakow.pl
 
-inline void scale_line(byte *in, byte *out, int ilen, int olen)
+static inline void scale_line(byte *in, byte *out, int ilen, int olen)
 {
 	int a = olen/ilen, b = olen%ilen;
 	int c = 0, i;
