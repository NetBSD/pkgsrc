$NetBSD: patch-dbeacon.h,v 1.1 2014/12/09 10:45:51 he Exp $

log() is also exported now.

--- dbeacon.h.orig	2007-06-25 00:32:38.000000000 +0000
+++ dbeacon.h
@@ -144,6 +144,7 @@ extern address beaconUnicastAddr;
 
 extern int verbose;
 
+void log(int level, const char *format, ...);
 void info(const char *format, ...);
 void fatal(const char *format, ...);
 
