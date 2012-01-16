$NetBSD: patch-src_FlightCrew_Validators_Opf_ReachabilityAnalysis.cpp,v 1.1 2012/01/16 21:05:02 ryoon Exp $

--- src/FlightCrew/Validators/Opf/ReachabilityAnalysis.cpp.orig	2011-09-01 12:47:32.000000000 +0000
+++ src/FlightCrew/Validators/Opf/ReachabilityAnalysis.cpp
@@ -26,7 +26,9 @@
 #include <XmlUtils.h>
 #include "Misc/DetermineMimetype.h"
 #include "Misc/Utilities.h"
+#include <boost/version.hpp>
 
+#if ( BOOST_VERSION < 104800 )
 namespace boost
 {
 
@@ -48,7 +50,7 @@ namespace filesystem3
 } // namespace filesystem3
 
 } // namespace boost
-
+#endif // BOOST_VERSION
 
 namespace FlightCrew
 {
