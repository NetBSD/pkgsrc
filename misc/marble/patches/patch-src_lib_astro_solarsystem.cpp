$NetBSD: patch-src_lib_astro_solarsystem.cpp,v 1.3 2025/12/21 14:38:39 markd Exp $

Avoid 'sun' definition.

--- src/lib/astro/solarsystem.cpp.orig	2025-10-06 03:25:22.000000000 +0000
+++ src/lib/astro/solarsystem.cpp
@@ -399,7 +399,7 @@ void SolarSystem::updateSolar()
 
     const double ae = 23454.77992; // 149597870.0/6378.14 =  1AE -> Earth Radii
     double dt, eps2;
-    Sun200 sun;
+    Sun200 msun;
     Moon200 moon;
     Plan200 pln;
     Vec3 coff, r1, v1;
@@ -410,7 +410,7 @@ void SolarSystem::updateSolar()
     // get positions in ecliptic coordinates of date
     dt = ss_time + ss_del_tdut / 86400.0;
     dt = julcent(dt);
-    ss_rs = sun.position(dt);
+    ss_rs = msun.position(dt);
     ss_rm = moon.position(dt) / ae;
     ss_pmer = pln.Mercury(dt);
     ss_pven = pln.Venus(dt);
@@ -1535,7 +1535,7 @@ Vec3 SolarSystem::SnPos(double &ep2, dou
     // return the apparent position of the Sun
     // and the Nutation ep2 value and the ecliptic longitude of the Sun els
 
-    Sun200 sun;
+    Sun200 msun;
     Mat3 mx;
     Vec3 rs, s;
     double t;
@@ -1543,7 +1543,7 @@ Vec3 SolarSystem::SnPos(double &ep2, dou
     t = ss_time + ss_del_tdut / 86400.0;
     t = julcent(t);
 
-    rs = sun.position(t);
+    rs = msun.position(t);
     s = carpol(rs);
     els = s[1];
 
