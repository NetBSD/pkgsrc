$NetBSD: patch-src_general_VectorOutOfRange.h,v 1.1 2013/04/29 21:31:10 joerg Exp $

--- src/general/VectorOutOfRange.h.orig	2013-04-29 20:21:11.000000000 +0000
+++ src/general/VectorOutOfRange.h
@@ -4,6 +4,7 @@
  * Copyright (c) 2007 Des Higgins, Julie Thompson and Toby Gibson.  
  */
 #include <stdexcept>
+#include <string>
 #include <exception>
 namespace clustalw
 {
