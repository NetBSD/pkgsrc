$NetBSD: patch-map_Projection__libproj.cpp,v 1.1 2012/03/15 22:46:01 plunky Exp $

--- map/Projection_libproj.cpp.orig	2012-03-15 16:25:37.000000000 +0000
+++ map/Projection_libproj.cpp
@@ -90,13 +90,13 @@ void Projection_libproj::setProjection(i
 	}
 	params[nbpar++] = (char*) "ellps=WGS84";
 	params[nbpar++] = (char*) "no_defs";
+	params[nbpar++] = (char*) "over";	// allow longitude > 180°
 
 	libProj = pj_init(nbpar, params);
 	if (!libProj)
 		printf("proj error: %s\n", pj_strerrno(pj_errno));
 	assert(libProj);
 	currentProj = code;
-	libProj->over = 1;		// allow longitude > 180°
 //printf("Projection: %s\n", libProj->descr);
 }
 
