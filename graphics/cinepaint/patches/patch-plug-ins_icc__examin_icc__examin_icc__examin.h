$NetBSD: patch-plug-ins_icc__examin_icc__examin_icc__examin.h,v 1.1 2013/03/28 21:43:06 joerg Exp $

--- plug-ins/icc_examin/icc_examin/icc_examin.h.orig	2013-03-28 13:10:09.000000000 +0000
+++ plug-ins/icc_examin/icc_examin/icc_examin.h
@@ -47,7 +47,6 @@ class  ICCwaehler;
 class  ICCexamin;
 extern ICCexamin *icc_examin;
 class  ICCexaminIO;
-class  icc_examin_ns::EinModell;
 
 namespace icc_examin_ns {
     enum IccGamutFormat {
