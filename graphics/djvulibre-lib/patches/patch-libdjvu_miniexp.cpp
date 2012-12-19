$NetBSD: patch-libdjvu_miniexp.cpp,v 1.1 2012/12/19 12:51:26 joerg Exp $

--- libdjvu/miniexp.cpp.orig	2012-12-19 10:39:45.000000000 +0000
+++ libdjvu/miniexp.cpp
@@ -43,6 +43,7 @@
 # define END_ANONYMOUS_NAMESPACE
 #endif
 
+#undef getc
 
 /* -------------------------------------------------- */
 /* ASSERT                                            */
