$NetBSD: patch-Makefile.swig,v 1.1 2013/05/11 21:37:46 joerg Exp $

--- Makefile.swig.orig	2013-05-10 14:15:43.000000000 +0000
+++ Makefile.swig
@@ -58,8 +58,7 @@ STD_SWIG_LA_LD_FLAGS =		\
 
 ## standard SWIG library additions for library creation
 
-STD_SWIG_LA_LIB_ADD =  		\
-	-lstdc++
+STD_SWIG_LA_LIB_ADD =
 
 ## standard SWIG CXXFLAGS
 ## This allows for code to be compiled with "-O1" instead of "-g -O2"
