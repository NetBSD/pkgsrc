$NetBSD: patch-expr.cc,v 1.1 2011/11/25 22:04:43 joerg Exp $

--- expr.cc.orig	2011-11-25 13:49:36.000000000 +0000
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
