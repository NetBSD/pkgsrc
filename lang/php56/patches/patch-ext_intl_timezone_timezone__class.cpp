$NetBSD: patch-ext_intl_timezone_timezone__class.cpp,v 1.2 2025/02/08 02:57:59 taca Exp $

* Fix build with textproc/icu-68.1.

--- ext/intl/timezone/timezone_class.cpp.orig	2019-01-09 09:54:13.000000000 +0000
+++ ext/intl/timezone/timezone_class.cpp
@@ -315,7 +315,7 @@ static HashTable *TimeZone_get_debug_inf
 
 	int32_t rawOffset, dstOffset;
 	UDate now = Calendar::getNow();
-	tz->getOffset(now, FALSE, rawOffset, dstOffset, uec);
+	tz->getOffset(now, false, rawOffset, dstOffset, uec);
 	if (U_FAILURE(uec)) {
 		return Z_ARRVAL(zv);
 	}
