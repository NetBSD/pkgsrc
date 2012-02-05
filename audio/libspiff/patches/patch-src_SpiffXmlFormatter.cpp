$NetBSD: patch-src_SpiffXmlFormatter.cpp,v 1.1 2012/02/05 20:05:56 sbd Exp $

--- src/SpiffXmlFormatter.cpp.orig	2008-09-21 18:21:45.000000000 +0000
+++ src/SpiffXmlFormatter.cpp
@@ -48,6 +48,7 @@
 #include <map>
 #include <list>
 #include <set>
+#include <cstdio>
 
 namespace Spiff {
 
