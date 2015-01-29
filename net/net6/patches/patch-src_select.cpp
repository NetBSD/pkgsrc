$NetBSD: patch-src_select.cpp,v 1.2 2015/01/29 02:59:27 mef Exp $

Fix build on SunOS.  Patch from Sebastian Wiedenroth.

--- src/select.cpp.orig	2009-08-24 12:18:29.000000000 +0000
+++ src/select.cpp
@@ -20,6 +20,7 @@
 
 #include <ctime>
 #include <limits>
+#include <cstring>
 #ifdef HAVE_SYS_SELECT_H
 # include <sys/select.h>
 #endif
