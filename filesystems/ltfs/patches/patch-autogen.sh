$NetBSD: patch-autogen.sh,v 1.1 2021/01/23 13:12:32 mef Exp $

autoconf-2.70 adhoc adaptation, 

--- autogen.sh.orig	2020-11-06 10:50:51.000000000 +0900
+++ autogen.sh	2021-01-23 21:39:46.992033563 +0900
@@ -46,6 +46,6 @@ else
 	libtoolize
 fi
 
-autoconf
-autoheader
-automake --add-missing --copy
+autoconf 			|| echo Ignore warning
+autoheader			|| echo Ignore warning
+automake --add-missing --copy	|| echo Ignore warning
