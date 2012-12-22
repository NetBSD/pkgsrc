$NetBSD: patch-algebra.cpp,v 1.1 2012/12/22 02:29:36 joerg Exp $

--- algebra.cpp.orig	2012-12-21 21:43:47.000000000 +0000
+++ algebra.cpp
@@ -58,7 +58,7 @@ template <class T> const T& AbstractEucl
 	Element g[3]={b, a};
 	unsigned int i0=0, i1=1, i2=2;
 
-	while (!Equal(g[i1], this->Identity()))
+	while (!this->Equal(g[i1], this->Identity()))
 	{
 		g[i2] = Mod(g[i0], g[i1]);
 		unsigned int t = i0; i0 = i1; i1 = i2; i2 = t;
