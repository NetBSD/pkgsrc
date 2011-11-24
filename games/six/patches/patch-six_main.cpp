$NetBSD: patch-six_main.cpp,v 1.1 2011/11/24 14:07:12 joerg Exp $

--- six/main.cpp.orig	2011-11-24 03:21:53.000000000 +0000
+++ six/main.cpp
@@ -11,6 +11,7 @@
 #include <klocale.h>
 #include <kmessagebox.h>
 #include <qfile.h>
+#include <cstdlib>
 
 using std::cin;
 
