$NetBSD: patch-src_SpiffPropsWriter.cpp,v 1.1 2012/02/05 20:05:56 sbd Exp $

--- src/SpiffPropsWriter.cpp.orig	2008-09-21 18:21:45.000000000 +0000
+++ src/SpiffPropsWriter.cpp
@@ -52,6 +52,7 @@
 #include <spiff/SpiffToolbox.h>
 #include <list>
 #include <cstdlib>
+#include <cstdio>
 
 namespace Spiff {
 
