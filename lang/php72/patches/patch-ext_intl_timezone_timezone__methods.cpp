$NetBSD: patch-ext_intl_timezone_timezone__methods.cpp,v 1.1 2020/11/11 20:01:34 markd Exp $

Use stdbool true/false macros.

--- ext/intl/timezone/timezone_methods.cpp.orig	2020-10-27 15:01:59.000000000 +0000
+++ ext/intl/timezone/timezone_methods.cpp
@@ -95,7 +95,7 @@ U_CFUNC PHP_FUNCTION(intltz_from_date_ti
 		RETURN_NULL();
 	}
 
-	tz = timezone_convert_datetimezone(tzobj->type, tzobj, FALSE, NULL,
+	tz = timezone_convert_datetimezone(tzobj->type, tzobj, false, NULL,
 		"intltz_from_date_time_zone");
 	if (tz == NULL) {
 		RETURN_NULL();
