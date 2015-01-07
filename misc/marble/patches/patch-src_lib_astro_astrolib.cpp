$NetBSD: patch-src_lib_astro_astrolib.cpp,v 1.1 2015/01/07 13:14:30 jperkin Exp $

Avoid 'sun' definition.

--- src/lib/astro/astrolib.cpp.orig	2014-10-23 21:53:08.000000000 +0000
+++ src/lib/astro/astrolib.cpp
@@ -2137,7 +2137,7 @@ void Eclipse::equ_sun_moon(double jd, do
 	Mat3 mx;
 
 	t = julcent (jd) + tdut / 3.15576e9;  // =(86400.0 * 36525.0);
-	rs = sun.position(t);
+	rs = msun.position(t);
 	rm = moon.position(t);
 	rs = eclequ(t,rs);
 	rm = eclequ(t,rm);
