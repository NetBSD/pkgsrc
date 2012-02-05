$NetBSD: patch-src_SpiffWriter.cpp,v 1.1 2012/02/05 20:05:56 sbd Exp $

--- src/SpiffWriter.cpp.orig	2008-09-21 18:21:45.000000000 +0000
+++ src/SpiffWriter.cpp
@@ -50,6 +50,7 @@
 #include <spiff/SpiffProps.h>
 #include <spiff/SpiffToolbox.h>
 #include <string>
+#include <cstdio>
 
 namespace Spiff {
 
