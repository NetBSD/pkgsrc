$NetBSD: patch-libqpdf_QPDF.cc,v 1.1 2013/03/02 17:58:35 joerg Exp $

--- libqpdf/QPDF.cc.orig	2013-03-01 23:02:42.000000000 +0000
+++ libqpdf/QPDF.cc
@@ -40,7 +40,7 @@ static char const* EMPTY_PDF =
     "%%EOF\n";
 
 
-QPDF::ObjGen::ObjGen(int o = 0, int g = 0) :
+QPDF::ObjGen::ObjGen(int o, int g) :
     obj(o),
     gen(g)
 {
