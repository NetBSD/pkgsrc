$NetBSD: patch-src_cpc_render5.c,v 1.1 2018/04/09 15:03:22 ryoon Exp $

Fix segfault on quit
https://github.com/rofl0r/arnold/commit/08915c467477ad2316cd5a8997a3538738be8945

--- src/cpc/render5.c.orig	2004-01-02 06:00:40.000000000 +0000
+++ src/cpc/render5.c
@@ -57,14 +57,16 @@ static int Render_CPCRenderHeight, Rende
 static int Render_CPCXOffset, Render_CPCYOffset;
 
 
-static void	Render_SetColourNULL(RGBCOLOUR *pColour,/*int Red, int Green, int Blue,*/ int Index);
+static void	Render_SetColourNULL(const RGBCOLOUR *pColour,/*int Red, 
+int Green, int Blue,*/ int Index);
 static void Render_PutDataWordNULL(int, unsigned long, int);
 static void Render_PutSyncNULL(int, int);
 static void Render_PutBorderNULL(int, int);
 static void Render_PutDataWordPLUSNULL(int HorizontalCount,unsigned long GraphicsData, int Line, unsigned long Mask, int *pPixels);
 
 static void (*pRender_DumpScreen)(void) = NULL;
-static void (*pRender_SetColour)(RGBCOLOUR *pColour,/*int, int, int,*/ int)=Render_SetColourNULL;
+static void (*pRender_SetColour)(const RGBCOLOUR *pColour,/*int, int, 
+int,*/ int)=Render_SetColourNULL;
 static void (*pRender_PutDataWord)(int, unsigned long, int)=Render_PutDataWordNULL;
 static void (*pRender_PutSync)(int, int)=Render_PutSyncNULL;
 static void (*pRender_PutBorder)(int, int)=Render_PutBorderNULL;
@@ -95,7 +97,8 @@ static PALETTE_ENTRY_RGB888    UnConvert
 static unsigned long    ConvertedColourTable[32];
 
 /* TrueColour RGB version of set colour */
-static void Render_TrueColourRGB_SetColour(RGBCOLOUR *pColour, /*int, int, int,*/int);
+static void Render_TrueColourRGB_SetColour(const RGBCOLOUR *pColour, 
+/*int, int, int,*/int);
 static void Render_TrueColourRGB_Setup(void);
 
 /* **** PALETTE stuff **** */
@@ -115,7 +118,8 @@ static PALETTE_ENTRY    CPCPalette[256];
 /* palette we build up */
 
 /* Paletted version of set colour */
-static void Render_Paletted_SetColour(RGBCOLOUR *pColour, /*int,int,int,*/int);
+static void Render_Paletted_SetColour(const RGBCOLOUR *pColour, 
+/*int,int,int,*/int);
 static void Render_Paletted_Setup(void);
 
 
@@ -211,7 +215,8 @@ static void Render_TrueColourRGB_Setup(v
 
 }
 
-void	Render_TrueColourRGB_SetColour(RGBCOLOUR *pColour,/*int Red, int Green, int Blue,*/ int
+void	Render_TrueColourRGB_SetColour(const RGBCOLOUR *pColour,/*int Red, 
+int Green, int Blue,*/ int
 Index)
 {
 	/* convert R,G,B into format of screen pixel */
@@ -343,7 +348,8 @@ int     GetIndexInPalette(int PenIndex, 
 }
 
 
-static void	Render_Paletted_SetColour(RGBCOLOUR *pColour,/*int Red, int Green, int Blue,*/
+static void	Render_Paletted_SetColour(const RGBCOLOUR *pColour,/*int 
+Red, int Green, int Blue,*/
 int Index)
 {
 	int PaletteIndex;
@@ -473,10 +479,12 @@ void    Render_Finish(void)
         if (pScreenBase!=NULL)
         {
                 free(pScreenBase);
+                pScreenBase = 0;
         }
 }
 
-void	Render_SetColourNULL(RGBCOLOUR *pColour,/*int Red, int Green, int Blue,*/ int Index)
+void	Render_SetColourNULL(const RGBCOLOUR *pColour,/*int Red, int 
+Green, int Blue,*/ int Index)
 {
 }
 
@@ -499,7 +507,8 @@ static void Render_PutDataWordPLUSNULL(i
 
 
 /* set pen index specified by Index to Red, Green and Blue specified */
-void    Render_SetColour(RGBCOLOUR *pColour,/*int Red,int Green,int Blue,*/ int Index)
+void    Render_SetColour(const RGBCOLOUR *pColour,/*int Red,int Green,int 
+Blue,*/ int Index)
 {
 	/* store chosen colour - in conversion table */
 	UnConvertedColourTable[Index].RGB.SeperateElements.u.element.Red = pColour->u.element.Red;
