$NetBSD: patch-ragel_javacodegen.cpp,v 1.2 2015/03/27 03:50:55 rodent Exp $

Make sure setiosflags is visible in the default scope.

--- ragel/javacodegen.cpp.orig	2013-06-07 15:59:16.000000000 +0000
+++ ragel/javacodegen.cpp
@@ -42,6 +42,7 @@
 
 using std::setw;
 using std::ios;
+using std::setiosflags;
 using std::ostringstream;
 using std::string;
 using std::cerr;
