$NetBSD: patch-ragel_javacodegen.cpp,v 1.1 2013/06/10 18:56:05 joerg Exp $

--- ragel/javacodegen.cpp.orig	2013-06-07 15:59:16.000000000 +0000
+++ ragel/javacodegen.cpp
@@ -42,6 +42,7 @@
 
 using std::setw;
 using std::ios;
+using std::setiosflags;
 using std::ostringstream;
 using std::string;
 using std::cerr;
