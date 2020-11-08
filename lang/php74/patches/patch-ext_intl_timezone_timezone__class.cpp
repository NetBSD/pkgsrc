$NetBSD: patch-ext_intl_timezone_timezone__class.cpp,v 1.2 2020/11/08 23:55:44 otis Exp $

Use stdbool true/false macros.

--- ext/intl/timezone/timezone_class.cpp.orig	2020-10-27 15:01:59.000000000 +0000
+++ ext/intl/timezone/timezone_class.cpp
@@ -325,7 +325,7 @@ static HashTable *TimeZone_get_debug_inf
 
 	int32_t rawOffset, dstOffset;
 	UDate now = Calendar::getNow();
-	tz->getOffset(now, FALSE, rawOffset, dstOffset, uec);
+	tz->getOffset(now, false, rawOffset, dstOffset, uec);
 	if (U_FAILURE(uec)) {
 		return debug_info;
 	}
