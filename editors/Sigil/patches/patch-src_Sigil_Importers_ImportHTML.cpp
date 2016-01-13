$NetBSD: patch-src_Sigil_Importers_ImportHTML.cpp,v 1.1 2016/01/13 23:55:42 joerg Exp $

--- src/Sigil/Importers/ImportHTML.cpp.orig	2016-01-12 20:49:21.000000000 +0000
+++ src/Sigil/Importers/ImportHTML.cpp
@@ -46,6 +46,7 @@
 #include "sigil_constants.h"
 #include "sigil_exception.h"
 
+using namespace boost::placeholders;
 using boost::tie;
 
 // Constructor;
