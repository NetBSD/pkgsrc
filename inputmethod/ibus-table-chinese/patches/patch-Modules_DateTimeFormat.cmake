$NetBSD: patch-Modules_DateTimeFormat.cmake,v 1.1 2011/09/01 11:46:06 obache Exp $

* -u is the POSIX standard way.

--- Modules/DateTimeFormat.cmake.orig	2011-08-03 00:21:35.000000000 +0000
+++ Modules/DateTimeFormat.cmake
@@ -28,7 +28,7 @@ IF(NOT DEFINED _DATE_TIME_FORMAT_CMAKE_)
 	IF(_locale)
 	    SET(ENV{LC_ALL} ${_locale})
 	ENDIF(_locale)
-	COMMAND_OUTPUT_TO_VARIABLE(${date_var} date --utc "${format}")
+	COMMAND_OUTPUT_TO_VARIABLE(${date_var} date -u "${format}")
     ENDMACRO(TODAY date_var format)
 
     TODAY(TODAY_CHANGELOG "+%a %b %d %Y" "C")
