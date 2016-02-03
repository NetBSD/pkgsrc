$NetBSD: patch-include-kicad_string.h,v 1.2 2016/02/03 19:34:33 bouyer Exp $

Standard string library should be included as well.

--- include/kicad_string.h.orig	2015-12-11 17:57:10.000000000 +0100
+++ include/kicad_string.h	2015-12-11 17:57:22.000000000 +0100
@@ -30,6 +30,7 @@
 #ifndef KICAD_STRING_H_
 #define KICAD_STRING_H_
 
+#include <string>
 #include <wx/string.h>
 #include <wx/filename.h>
 
