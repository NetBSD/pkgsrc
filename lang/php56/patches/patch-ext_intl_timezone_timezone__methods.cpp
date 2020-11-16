$NetBSD: patch-ext_intl_timezone_timezone__methods.cpp,v 1.1 2020/11/16 12:10:05 ryoon Exp $

--- ext/intl/timezone/timezone_methods.cpp.orig	2019-01-09 09:54:13.000000000 +0000
+++ ext/intl/timezone/timezone_methods.cpp
@@ -92,7 +92,7 @@ U_CFUNC PHP_FUNCTION(intltz_from_date_ti
 		RETURN_NULL();
 	}
 
-	tz = timezone_convert_datetimezone(tzobj->type, tzobj, FALSE, NULL,
+	tz = timezone_convert_datetimezone(tzobj->type, tzobj, false, NULL,
 		"intltz_from_date_time_zone" TSRMLS_CC);
 	if (tz == NULL) {
 		RETURN_NULL();
