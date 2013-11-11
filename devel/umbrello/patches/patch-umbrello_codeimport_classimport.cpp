$NetBSD: patch-umbrello_codeimport_classimport.cpp,v 1.1 2013/11/11 16:47:07 joerg Exp $

Patches from upstream.

--- umbrello/codeimport/classimport.cpp.orig	2013-06-28 18:06:03.000000000 +0000
+++ umbrello/codeimport/classimport.cpp
@@ -20,9 +20,7 @@
 #include "javaimport.h"
 #include "adaimport.h"
 #include "pascalimport.h"
-#ifndef DISABLE_CPP_IMPORT
 #include "cppimport.h"
-#endif
 #include "csharpimport.h"
 #include "codeimpthread.h"
 
@@ -52,13 +50,8 @@ ClassImport *ClassImport::createImporter
         classImporter = new PascalImport(thread);
     else if (fileName.endsWith(QLatin1String(".cs")))
         classImporter = new CSharpImport(thread);
-#ifndef DISABLE_CPP_IMPORT
     else
         classImporter = new CppImport(thread);  // the default.
-#else
-    else 
-        classImporter = 0;
-#endif
     return classImporter;
 }
 
