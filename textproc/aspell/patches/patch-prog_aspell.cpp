$NetBSD: patch-prog_aspell.cpp,v 1.2 2019/09/15 06:53:36 maya Exp $

--- prog/aspell.cpp.orig	2013-08-16 12:16:40.000000000 +0000
+++ prog/aspell.cpp
@@ -25,6 +25,7 @@
 # include <langinfo.h>
 #endif
 
+#include "errors.hpp"
 #include "aspell.h"
 
 #include <sys/types.h>
@@ -41,7 +42,6 @@
 #include "convert.hpp"
 #include "document_checker.hpp"
 #include "enumeration.hpp"
-#include "errors.hpp"
 #include "file_util.hpp"
 #include "fstream.hpp"
 #include "info.hpp"
