$NetBSD: patch-core_cmake_BareosTimeFunctions.cmake,v 1.1 2020/07/28 06:36:29 kardel Exp $

Use the POSIX compatible way of doing date calculations.

--- core/cmake/BareosTimeFunctions.cmake.orig	2020-04-16 08:31:41.000000000 +0000
+++ core/cmake/BareosTimeFunctions.cmake
@@ -37,8 +37,8 @@ function(
     execute_process(
       COMMAND
         ${DATECMD}
-        --utc
-        "--date=@${at}"
+        -u
+        "-d @${at}"
         "+${format}"
       OUTPUT_VARIABLE out
       OUTPUT_STRIP_TRAILING_WHITESPACE
