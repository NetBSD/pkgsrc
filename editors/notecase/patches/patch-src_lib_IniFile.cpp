$NetBSD: patch-src_lib_IniFile.cpp,v 1.1 2013/05/23 18:39:35 joerg Exp $

--- src/lib/IniFile.cpp.orig	2013-05-23 16:49:49.000000000 +0000
+++ src/lib/IniFile.cpp
@@ -8,6 +8,7 @@
 
 #include "IniFile.h"
 #include <algorithm>    //find() function
+#include <cstdlib>
 #include <string>
 #include "File64.h"
 #include "FilePath.h"
