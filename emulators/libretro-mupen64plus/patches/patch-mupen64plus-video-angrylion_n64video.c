$NetBSD: patch-mupen64plus-video-angrylion_n64video.c,v 1.1 2017/06/17 19:42:03 joerg Exp $

C99's inline has different semantic.

--- mupen64plus-video-angrylion/n64video.c.orig	2017-06-16 12:04:46.824147448 +0000
+++ mupen64plus-video-angrylion/n64video.c
@@ -218,7 +218,7 @@ static void compute_cvg_flip(INT32 scanl
 STRICTINLINE UINT32 z_decompress(UINT32 rawz);
 STRICTINLINE UINT32 dz_decompress(UINT32 compresseddz);
 STRICTINLINE UINT32 dz_compress(UINT32 value);
-INLINE void z_build_com_table(void);
+void z_build_com_table(void);
 static void precalc_cvmask_derivatives(void);
 STRICTINLINE UINT16 decompress_cvmask_frombyte(UINT8 byte);
 STRICTINLINE void lookup_cvmask_derivatives(UINT32 mask, UINT8* offx, UINT8* offy, UINT32* curpixel_cvg, UINT32* curpixel_cvbit);
@@ -698,7 +698,7 @@ INLINE void SET_SUBA_RGB_INPUT(INT32 **i
     }
 }
 
-INLINE void SET_SUBB_RGB_INPUT(INT32 **input_r, INT32 **input_g, INT32 **input_b, int code)
+void SET_SUBB_RGB_INPUT(INT32 **input_r, INT32 **input_g, INT32 **input_b, int code)
 {
     switch (code & 0xf)
     {
@@ -717,7 +717,7 @@ INLINE void SET_SUBB_RGB_INPUT(INT32 **i
     }
 }
 
-INLINE void SET_MUL_RGB_INPUT(INT32 **input_r, INT32 **input_g, INT32 **input_b, int code)
+void SET_MUL_RGB_INPUT(INT32 **input_r, INT32 **input_g, INT32 **input_b, int code)
 {
     switch (code & 0x1f)
     {
@@ -745,7 +745,7 @@ INLINE void SET_MUL_RGB_INPUT(INT32 **in
     }
 }
 
-INLINE void SET_ADD_RGB_INPUT(INT32 **input_r, INT32 **input_g, INT32 **input_b, int code)
+void SET_ADD_RGB_INPUT(INT32 **input_r, INT32 **input_g, INT32 **input_b, int code)
 {
     switch (code & 0x7)
     {
@@ -760,7 +760,7 @@ INLINE void SET_ADD_RGB_INPUT(INT32 **in
     }
 }
 
-INLINE void SET_SUB_ALPHA_INPUT(INT32 **input, int code)
+void SET_SUB_ALPHA_INPUT(INT32 **input, int code)
 {
     switch (code & 0x7)
     {
@@ -775,7 +775,7 @@ INLINE void SET_SUB_ALPHA_INPUT(INT32 **
     }
 }
 
-INLINE void SET_MUL_ALPHA_INPUT(INT32 **input, int code)
+void SET_MUL_ALPHA_INPUT(INT32 **input, int code)
 {
     switch (code & 0x7)
     {
@@ -1129,7 +1129,7 @@ static void precalculate_everything(void
     return;
 }
 
-INLINE void SET_BLENDER_INPUT(int cycle, int which, INT32 **input_r, INT32 **input_g, INT32 **input_b, INT32 **input_a, int a, int b)
+void SET_BLENDER_INPUT(int cycle, int which, INT32 **input_r, INT32 **input_g, INT32 **input_b, INT32 **input_a, int a, int b)
 {
 
     switch (a & 0x3)
@@ -5837,7 +5837,7 @@ STRICTINLINE UINT32 z_decompress(UINT32 
     return (z_complete_dec_table[zb >> 2]);
 }
 
-INLINE void z_build_com_table(void)
+void z_build_com_table(void)
 {
     register int z;
     UINT16 altmem = 0;
@@ -6220,14 +6220,14 @@ STRICTINLINE INT32 CLIP(INT32 value,INT3
         return value;
 }
 
-INLINE void calculate_clamp_diffs(UINT32 i)
+void calculate_clamp_diffs(UINT32 i)
 {
     tile[i].f.clampdiffs = ((tile[i].sh >> 2) - (tile[i].sl >> 2)) & 0x3ff;
     tile[i].f.clampdifft = ((tile[i].th >> 2) - (tile[i].tl >> 2)) & 0x3ff;
 }
 
 
-INLINE void calculate_tile_derivs(UINT32 i)
+void calculate_tile_derivs(UINT32 i)
 {
     tile[i].f.clampens = tile[i].cs || !tile[i].mask_s;
     tile[i].f.clampent = tile[i].ct || !tile[i].mask_t;
