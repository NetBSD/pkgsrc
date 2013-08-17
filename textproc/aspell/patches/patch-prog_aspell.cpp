$NetBSD: patch-prog_aspell.cpp,v 1.1 2013/08/17 11:19:03 joerg Exp $

--- prog/aspell.cpp.orig	2013-08-16 12:16:40.000000000 +0000
+++ prog/aspell.cpp
@@ -25,6 +25,7 @@
 # include <langinfo.h>
 #endif
 
+#include "errors.hpp"
 #include "aspell.h"
 
 #ifdef USE_FILE_INO
@@ -40,7 +41,6 @@
 #include "convert.hpp"
 #include "document_checker.hpp"
 #include "enumeration.hpp"
-#include "errors.hpp"
 #include "file_util.hpp"
 #include "fstream.hpp"
 #include "info.hpp"
