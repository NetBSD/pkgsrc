$NetBSD: patch-core_cmake_BareosTimeFunctions.cmake,v 1.2 2021/02/01 09:08:43 kardel Exp $

	use the POSIX compatible way of doing date calculations.

--- core/cmake/BareosTimeFunctions.cmake.orig	2021-01-22 12:44:55.503593980 +0000
+++ core/cmake/BareosTimeFunctions.cmake
@@ -30,7 +30,7 @@ function(timestamp_at at result format)
     set(old_lang "$ENV{LC_ALL}")
     set(ENV{LC_ALL} "C")
     execute_process(
-      COMMAND ${DATECMD} --utc "--date=@${at}" "+${format}"
+      COMMAND ${DATECMD} -u "--date=@${at}" "+${format}"
       OUTPUT_VARIABLE out
       OUTPUT_STRIP_TRAILING_WHITESPACE
     )
