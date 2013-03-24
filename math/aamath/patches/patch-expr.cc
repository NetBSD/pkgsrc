$NetBSD: patch-expr.cc,v 1.2 2013/03/24 16:52:35 joerg Exp $

--- expr.cc.orig	2005-03-08 02:00:02.000000000 +0000
+++ expr.cc
@@ -1192,7 +1192,7 @@ IntegralOnInterval::render_head() const
 
 class SumSymbol : public OpSymbol {
   public:
-	void render(Canvas& c, int r, int c) const;
+	void render(Canvas& canvas, int r, int c) const;
 };
 
 void
@@ -1208,7 +1208,7 @@ SumSymbol::render(Canvas& canvas, int r,
 
 class ProductSymbol : public OpSymbol {
   public:
-	void render(Canvas& c, int r, int c) const;
+	void render(Canvas& canvas, int r, int c) const;
 };
 
 void
@@ -1612,7 +1612,7 @@ Matrix::render() const
 	int cols = num_cols();
 	int rows = num_rows();
 
-	CanvasPtr ec[cols * rows];
+	CanvasPtr *ec = new CanvasPtr[cols * rows];
 	Size sz[cols * rows];
 
 	int row_height[rows];
@@ -1692,6 +1692,8 @@ Matrix::render() const
 
 	canvas->center();
 
+	delete[] ec;
+
 	return canvas;
 }
 
