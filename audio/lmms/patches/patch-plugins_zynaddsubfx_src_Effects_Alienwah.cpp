$NetBSD: patch-plugins_zynaddsubfx_src_Effects_Alienwah.cpp,v 1.1 2013/06/27 15:48:11 joerg Exp $

--- plugins/zynaddsubfx/src/Effects/Alienwah.cpp.orig	2013-06-27 13:21:58.000000000 +0000
+++ plugins/zynaddsubfx/src/Effects/Alienwah.cpp
@@ -67,7 +67,7 @@ void Alienwah::out(const Stereo<float *>
         tmp = clfol * x + oldclfol * x1;
 
         out = tmp * oldl[oldk];
-        out.real() += (1 - fabs(fb)) * smp.l[i] * (1.0 - panning);
+        out.real(out.real() + (1 - fabs(fb)) * smp.l[i] * (1.0 - panning));
 
         oldl[oldk]  = out;
         REALTYPE l = out.real() * 10.0 * (fb + 0.1);
@@ -76,7 +76,7 @@ void Alienwah::out(const Stereo<float *>
         tmp = clfor * x + oldclfor * x1;
 
         out = tmp * oldr[oldk];
-        out.real() += (1 - fabs(fb)) * smp.r[i] * (1.0 - panning);
+        out.real(out.real() + (1 - fabs(fb)) * smp.r[i] * (1.0 - panning));
 
         oldr[oldk]  = out;
         REALTYPE r = out.real() * 10.0 * (fb + 0.1);
