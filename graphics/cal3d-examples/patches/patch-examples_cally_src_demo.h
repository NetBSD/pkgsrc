$NetBSD: patch-examples_cally_src_demo.h,v 1.1 2011/11/26 17:12:24 joerg Exp $

--- examples/cally/src/demo.h.orig	2003-09-08 03:03:32.000000000 +0000
+++ examples/cally/src/demo.h
@@ -11,6 +11,9 @@
 #ifndef DEMO_H
 #define DEMO_H
 
+#include <cstring>
+#include <strings.h>
+
 //----------------------------------------------------------------------------//
 // Includes                                                                   //
 //----------------------------------------------------------------------------//
