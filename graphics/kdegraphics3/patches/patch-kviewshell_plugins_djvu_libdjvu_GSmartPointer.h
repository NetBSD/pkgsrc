$NetBSD: patch-kviewshell_plugins_djvu_libdjvu_GSmartPointer.h,v 1.2 2014/09/08 15:08:14 wiz Exp $

Include cstddef for size_t.

--- kviewshell/plugins/djvu/libdjvu/GSmartPointer.h.orig	2005-09-10 08:19:20.000000000 +0000
+++ kviewshell/plugins/djvu/libdjvu/GSmartPointer.h
@@ -56,2 +56,4 @@
 
+#include <cstddef>
+
 #ifndef _GSMARTPOINTER_H_
