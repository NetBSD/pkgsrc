$NetBSD: patch-src_formats_confabreport.cpp,v 1.1 2019/11/20 17:02:12 kamil Exp $

--- src/formats/confabreport.cpp.orig	2019-10-07 16:39:17.000000000 +0000
+++ src/formats/confabreport.cpp
@@ -33,6 +33,7 @@ as an example.
 #include <openbabel/babelconfig.h>
 #include <openbabel/obmolecformat.h>
 #include <openbabel/math/align.h>
+#include <algorithm>
 
 using namespace std;
 namespace OpenBabel
@@ -224,4 +225,3 @@ bool ConfabReport::WriteMolecule(OBBase*
 }
 
 } //namespace OpenBabel
-
