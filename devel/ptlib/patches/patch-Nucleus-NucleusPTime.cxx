$NetBSD: patch-Nucleus-NucleusPTime.cxx,v 1.1 2011/12/04 21:59:36 marino Exp $

--- src/ptlib/Nucleus++/NucleusPTime.cxx.orig	2009-09-21 00:25:17.000000000 +0000
+++ src/ptlib/Nucleus++/NucleusPTime.cxx
@@ -302,7 +302,7 @@ int PTime::GetTimeZone(PTime::TimeZoneTy
     return tz;
   else
     return tz + ::daylight*60;
-#elif defined(P_FREEBSD)
+#elif defined(P_FREEBSD) || defined(P_DRAGONFLY)
   time_t t;
   time(&t);
   struct tm  * tm = localtime(&t);
