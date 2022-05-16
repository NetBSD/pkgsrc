$NetBSD: patch-solaris_Platform.h,v 1.1 2022/05/16 12:14:22 jperkin Exp $

Remove unwanted and breaking includes.

--- solaris/Platform.h.orig	2022-05-01 06:31:20.000000000 +0000
+++ solaris/Platform.h
@@ -17,16 +17,12 @@ in the source distribution for its full
  * Since ncruses macros use the ERR macro, we can not use another name.
  */
 #undef ERR
-#include <libproc.h>
 #undef ERR
 #define ERR (-1)
 
 #include <signal.h>
 #include <stdbool.h>
 
-#include <sys/mkdev.h>
-#include <sys/proc.h>
-#include <sys/types.h>
 
 #include "Action.h"
 #include "BatteryMeter.h"
