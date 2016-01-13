$NetBSD: patch-src_Sigil_BookManipulation_Headings.cpp,v 1.1 2016/01/13 23:55:42 joerg Exp $

--- src/Sigil/BookManipulation/Headings.cpp.orig	2016-01-12 20:35:47.000000000 +0000
+++ src/Sigil/BookManipulation/Headings.cpp
@@ -35,7 +35,7 @@
 #include "sigil_constants.h"
 
 using boost::make_tuple;
-
+using namespace boost::placeholders;
 
 // The maximum allowed distance (in lines) that a heading
 // can be located from a body tag and still
