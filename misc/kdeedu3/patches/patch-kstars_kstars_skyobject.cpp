$NetBSD: patch-kstars_kstars_skyobject.cpp,v 1.1 2012/06/25 11:31:20 joerg Exp $

--- kstars/kstars/skyobject.cpp.orig	2012-06-18 20:34:47.000000000 +0000
+++ kstars/kstars/skyobject.cpp
@@ -101,7 +101,8 @@ QTime SkyObject::riseSetTime( const KSta
 	//to bring it above the horizon
 	KStarsDateTime dt2 = dt;
 	SkyPoint p = recomputeCoords( dt, geo );
-	p.EquatorialToHorizontal( &(geo->GSTtoLST( dt.gst() )), geo->lat() );
+	dms lst(geo->GSTtoLST( dt.gst() ));
+	p.EquatorialToHorizontal( &lst, geo->lat() );
 	if ( p.alt()->Degrees() < 0.0 ) {
 		if ( p.az()->Degrees() < 180.0 ) { //object has not risen yet
 			dt2 = dt.addSecs( 12.*3600. );
