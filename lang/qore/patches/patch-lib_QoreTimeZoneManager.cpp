$NetBSD: patch-lib_QoreTimeZoneManager.cpp,v 1.1 2015/05/02 10:36:29 nros Exp $
* Fix build on OpenBSD.
  Committed upstream:
  http://sourceforge.net/p/qore/code/7208/
--- lib/QoreTimeZoneManager.cpp.orig	2015-05-02 12:21:24.000000000 +0000
+++ lib/QoreTimeZoneManager.cpp
@@ -27,7 +27,6 @@
 
 #include <stdio.h>
 #include <time.h>
-#include <sys/timeb.h>
 
 #ifdef HAVE_GLOB_H
 #include <glob.h>
