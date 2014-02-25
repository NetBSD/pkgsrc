$NetBSD: patch-plugins_actor_G-Force_Common_GeneralTools_UtilStr.cpp,v 1.1 2014/02/25 01:45:53 wiedi Exp $

fix "pow() is ambiguous" on SunOS
--- plugins/actor/G-Force/Common/GeneralTools/UtilStr.cpp.orig	2005-12-06 10:48:28.000000000 +0000
+++ plugins/actor/G-Force/Common/GeneralTools/UtilStr.cpp
@@ -1213,7 +1213,7 @@ void UtilStr::SetFloatValue( float inVal
 		deci_digits = 10 - left_digits;
 		if ( deci_digits > inPercision )
 			deci_digits = inPercision;
-		scale =  pow( 10, deci_digits );
+		scale =  pow( 10, (double) deci_digits );
 		SetValue( inValue * scale, scale, deci_digits ); }
 	else
 		Assign( "Overflow" );
