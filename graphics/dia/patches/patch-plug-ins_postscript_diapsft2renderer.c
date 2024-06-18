$NetBSD: patch-plug-ins_postscript_diapsft2renderer.c,v 1.3 2024/06/18 09:07:25 markd Exp $

From e5557aa1d396bc3ca80240f7b5c0a1831a5cf209 Mon Sep 17 00:00:00 2001
From: Hans Breuer <hans@breuer.org>
Date: Sat, 4 May 2013 15:20:15 +0200
Subject: [PATCH] [warningectomy] initialization from incompatible pointer type

FT_Outline_Funcs take const FT_Vector* nowadays.

diff --git a/plug-ins/postscript/diapsft2renderer.c b/plug-ins/postscript/diapsft2renderer.c
index 63aac74b5..ed4182e5e 100644
--- plug-ins/postscript/diapsft2renderer.c
+++ plug-ins/postscript/diapsft2renderer.c
@@ -61,16 +61,16 @@ void draw_bezier_outline(DiaPsRenderer *renderer,
 			 double pos_y
 			 );
 /* Countour traveling functions */
-static int paps_move_to( FT_Vector* to,
+static int paps_move_to( const FT_Vector* to,
 			 void *user_data);
-static int paps_line_to( FT_Vector*  to,
+static int paps_line_to( const FT_Vector*  to,
 			 void *user_data);
-static int paps_conic_to( FT_Vector*  control,
-			  FT_Vector*  to,
+static int paps_conic_to( const FT_Vector*  control,
+			  const FT_Vector*  to,
 			  void *user_data);
-static int paps_cubic_to( FT_Vector*  control1,
-			  FT_Vector*  control2,
-			  FT_Vector*  to,
+static int paps_cubic_to( const FT_Vector*  control1,
+			  const FT_Vector*  control2,
+			  const FT_Vector*  to,
 			  void *user_data);
 
 static void dia_ps_ft2_renderer_class_init (DiaPsFt2RendererClass *klass);
@@ -111,7 +111,7 @@ set_font(DiaRenderer *self, DiaFont *font, real height)
 /*======================================================================
   outline traversing functions.
   ----------------------------------------------------------------------*/
-static int paps_move_to( FT_Vector* to,
+static int paps_move_to( const FT_Vector* to,
 			 void *user_data)
 {
   OutlineInfo *outline_info = (OutlineInfo*)user_data;
@@ -121,7 +121,7 @@ static int paps_move_to( FT_Vector* to,
   return 0;
 }
 
-static int paps_line_to( FT_Vector*  to,
+static int paps_line_to( const FT_Vector*  to,
 			 void *user_data)
 {
   OutlineInfo *outline_info = (OutlineInfo*)user_data;
@@ -131,8 +131,8 @@ static int paps_line_to( FT_Vector*  to,
   return 0;
 }
 
-static int paps_conic_to( FT_Vector*  control,
-			  FT_Vector*  to,
+static int paps_conic_to( const FT_Vector*  control,
+			  const FT_Vector*  to,
 			  void *user_data)
 {
   OutlineInfo *outline_info = (OutlineInfo*)user_data;
@@ -144,9 +144,9 @@ static int paps_conic_to( FT_Vector*  control,
   return 0;
 }
 
-static int paps_cubic_to( FT_Vector*  control1,
-			  FT_Vector*  control2,
-			  FT_Vector*  to,
+static int paps_cubic_to( const FT_Vector*  control1,
+			  const FT_Vector*  control2,
+			  const FT_Vector*  to,
 			  void *user_data)
 {
   OutlineInfo *outline_info = (OutlineInfo*)user_data;
-- 
GitLab

