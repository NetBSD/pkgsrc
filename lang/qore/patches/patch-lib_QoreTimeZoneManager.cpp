$NetBSD: patch-lib_QoreTimeZoneManager.cpp,v 1.2 2016/03/09 21:32:41 nros Exp $
* Fix build on OpenBSD.
  Committed upstream:
  http://sourceforge.net/p/qore/code/7208/
--- lib/QoreTimeZoneManager.cpp.orig	2014-06-07 08:17:39.000000000 +0000
+++ lib/QoreTimeZoneManager.cpp
@@ -27,7 +27,6 @@
 
 #include <stdio.h>
 #include <time.h>
-#include <sys/timeb.h>
 
 #ifdef HAVE_GLOB_H
 #include <glob.h>
