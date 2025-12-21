$NetBSD: patch-src_lib_astro_astrolib.cpp,v 1.2 2025/12/21 14:38:39 markd Exp $

Avoid 'sun' definition.

--- src/lib/astro/astrolib.cpp.orig	2025-10-06 03:25:22.000000000 +0000
+++ src/lib/astro/astrolib.cpp
@@ -2183,7 +2183,7 @@ void Eclipse::equ_sun_moon(double jd, do
     Mat3 mx;
 
     t = julcent(jd) + tdut / 3.15576e9; // =(86400.0 * 36525.0);
-    rs = sun.position(t);
+    rs = msun.position(t);
     rm = moon.position(t);
     rs = eclequ(t, rs);
     rm = eclequ(t, rm);
