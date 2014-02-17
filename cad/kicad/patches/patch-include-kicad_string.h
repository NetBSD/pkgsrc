$NetBSD: patch-include-kicad_string.h,v 1.1.1.1 2014/02/17 20:38:59 bouyer Exp $

Standard string library should be included as well.

--- include/kicad_string.h.orig	2011-11-27 11:43:14.000000000 +0000
+++ include/kicad_string.h
@@ -9,6 +9,7 @@
 #ifndef KICAD_STRING_H_
 #define KICAD_STRING_H_
 
+#include <string>
 #include <wx/string.h>
 
 
