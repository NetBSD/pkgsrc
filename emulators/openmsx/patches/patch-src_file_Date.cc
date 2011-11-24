$NetBSD: patch-src_file_Date.cc,v 1.1 2011/11/24 14:12:21 joerg Exp $

--- src/file/Date.cc.orig	2011-11-24 02:42:56.000000000 +0000
+++ src/file/Date.cc
@@ -4,6 +4,7 @@
 #include <sstream>
 #include <iomanip>
 #include <cstdio>
+#include <cstring>
 
 namespace openmsx {
 
