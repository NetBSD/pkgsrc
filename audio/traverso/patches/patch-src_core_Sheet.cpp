$NetBSD: patch-src_core_Sheet.cpp,v 1.1 2020/04/24 08:43:08 nia Exp $

Use standard LLONG_MAX definition.

--- src/core/Sheet.cpp.orig	2017-10-09 18:38:43.000000000 +0000
+++ src/core/Sheet.cpp
@@ -397,7 +397,7 @@ int Sheet::prepare_export(ExportSpecific
 		m_rendering = true;
 	}
 
-	spec->startLocation = LONG_LONG_MAX;
+	spec->startLocation = LLONG_MAX;
 	spec->endLocation = TimeRef();
 
 	TimeRef endlocation, startlocation;
