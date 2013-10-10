$NetBSD: patch-libfreerdp-codec_color.c,v 1.1 2013/10/10 00:09:07 joerg Exp $

--- libfreerdp-codec/color.c.orig	2013-10-09 23:34:52.000000000 +0000
+++ libfreerdp-codec/color.c
@@ -86,7 +86,7 @@ void freerdp_set_pixel(uint8* data, int 
 	}
 }
 
-INLINE void freerdp_color_split_rgb(uint32* color, int bpp, uint8* red, uint8* green, uint8* blue, uint8* alpha, HCLRCONV clrconv)
+static INLINE void freerdp_color_split_rgb(uint32* color, int bpp, uint8* red, uint8* green, uint8* blue, uint8* alpha, HCLRCONV clrconv)
 {
 	*red = *green = *blue = 0;
 	*alpha = (clrconv->alpha) ? 0xFF : 0x00;
@@ -137,7 +137,7 @@ INLINE void freerdp_color_split_rgb(uint
 	}
 }
 
-INLINE void freerdp_color_split_bgr(uint32* color, int bpp, uint8* red, uint8* green, uint8* blue, uint8* alpha, HCLRCONV clrconv)
+static INLINE void freerdp_color_split_bgr(uint32* color, int bpp, uint8* red, uint8* green, uint8* blue, uint8* alpha, HCLRCONV clrconv)
 {
 	*red = *green = *blue = 0;
 	*alpha = (clrconv->alpha) ? 0xFF : 0x00;
@@ -188,7 +188,7 @@ INLINE void freerdp_color_split_bgr(uint
 	}
 }
 
-INLINE void freerdp_color_make_rgb(uint32* color, int bpp, uint8* red, uint8* green, uint8* blue, uint8* alpha, HCLRCONV clrconv)
+static INLINE void freerdp_color_make_rgb(uint32* color, int bpp, uint8* red, uint8* green, uint8* blue, uint8* alpha, HCLRCONV clrconv)
 {
 	switch (bpp)
 	{
@@ -229,7 +229,7 @@ INLINE void freerdp_color_make_rgb(uint3
 	}
 }
 
-INLINE void freerdp_color_make_bgr(uint32* color, int bpp, uint8* red, uint8* green, uint8* blue, uint8* alpha, HCLRCONV clrconv)
+static INLINE void freerdp_color_make_bgr(uint32* color, int bpp, uint8* red, uint8* green, uint8* blue, uint8* alpha, HCLRCONV clrconv)
 {
 	switch (bpp)
 	{
