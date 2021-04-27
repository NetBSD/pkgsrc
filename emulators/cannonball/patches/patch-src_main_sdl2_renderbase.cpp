$NetBSD: patch-src_main_sdl2_renderbase.cpp,v 1.1 2021/04/27 14:39:19 fox Exp $

Fixes the error: no member named 'round' in namespace 'std'

--- src/main/sdl2/renderbase.cpp.orig	2021-04-27 14:18:09.955963096 +0000
+++ src/main/sdl2/renderbase.cpp
@@ -1,5 +1,6 @@
 #include "renderbase.hpp"
 #include <iostream>
+#include <cmath>
 
 RenderBase::RenderBase()
 {
