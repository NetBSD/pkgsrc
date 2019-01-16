$NetBSD: patch-sunwait.cpp,v 1.1 2019/01/16 14:43:22 martin Exp $

Fix typo that causes a warning from newer gcc.

--- sunwait.cpp.orig	2015-09-20 16:07:55.000000000 +0200
+++ sunwait.cpp	2018-07-19 14:15:25.334426961 +0200
@@ -661,7 +661,7 @@
     if (pRun->debug == ONOFF_ON) printf ("Debug: argv[%d]: >%s<\n", i, arg);
 
     // Strip any hyphen from arguments, but not negative signs of numbers
-    if (arg[0] == '-' && arg[1] != '\0' && !isdigit(arg[1])) *arg++;
+    if (arg[0] == '-' && arg[1] != '\0' && !isdigit(arg[1])) arg++;
 
     // Normal help or version info
          if   (!strcmp (arg, "v")             ||
