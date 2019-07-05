$NetBSD: patch-source_src_main.cpp,v 1.1 2019/07/05 08:01:31 nia Exp $

[PATCH] fix some errors and warnings for GCC 6

- do not use std::abs() because math.h includes one, that converts ints
  to double. Use own iabs(), which directly uses labs() instead.
- don't use the word "gamma" as name for variables
- don't use a homebrew round() function

https://github.com/assaultcube/AC/commit/752950989b4e286459ca9aee3d61a868d7b20fa4

--- source/src/main.cpp.orig	2013-10-29 09:33:15.000000000 +0000
+++ source/src/main.cpp
@@ -513,11 +513,11 @@ void setresdata(char *s, enet_uint32 c)
 COMMANDF(screenres, "ii", (int *w, int *h) { screenres(*w, *h); });
 
 static int curgamma = 100;
-VARFP(gamma, 30, 100, 300,
+VARNFP(gamma, vgamma, 30, 100, 300,
 {
-    if(gamma == curgamma) return;
-    curgamma = gamma;
-    float f = gamma/100.0f;
+    if(vgamma == curgamma) return;
+    curgamma = vgamma;
+    float f = vgamma/100.0f;
     if(SDL_SetGamma(f,f,f)==-1) conoutf("Could not set gamma: %s", SDL_GetError());
 });
 
