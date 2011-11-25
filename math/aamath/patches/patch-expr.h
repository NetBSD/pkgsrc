$NetBSD: patch-expr.h,v 1.1 2011/11/25 22:04:43 joerg Exp $

--- expr.h.orig	2011-11-25 13:49:05.000000000 +0000
+++ expr.h
@@ -451,7 +451,7 @@ class Integral : public OpOnFunction {
 
 	virtual CanvasPtr render_head() const;
 
-	void render_symbol(Canvas& c, int r, int c, int h) const;
+	void render_symbol(Canvas& canvas, int r, int c, int h) const;
 
 	virtual CanvasPtr render() const;
 };
@@ -467,7 +467,7 @@ class IntegralOnInterval : public Integr
 
 class OpSymbol {
   public:
-	virtual void render(Canvas& c, int r, int c) const = 0;
+	virtual void render(Canvas& canvas, int r, int c) const = 0;
 };
 
 class SumOrProduct : public OpOnFunction {
