$NetBSD: patch-src_chartimg.cpp,v 1.1 2016/03/14 11:01:06 bouyer Exp $
From master:
https://github.com/OpenCPN/OpenCPN/commit/39f9b1af047330d0a8ea3a72ac66ddb15ff96285

--- src/chartimg.cpp.orig
+++ src/chartimg.cpp
@@ -2886,7 +2886,7 @@ void ChartBaseBSB::latlong_to_chartpix(double lat, double lon, double &pixx, dou
                   alat = lat + m_lat_datum_adjust;
 
                 //      Get e/n from  Projection
-                  xlon = AdjustLongitude(xlon);
+                  xlon = AdjustLongitude(alon);
 
                   toSM_ECC(alat, xlon, m_proj_lat, m_proj_lon, &easting, &northing);

