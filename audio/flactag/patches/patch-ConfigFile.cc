$NetBSD: patch-ConfigFile.cc,v 1.1 2012/02/04 09:26:11 sbd Exp $

--- ConfigFile.cc.orig	2008-12-16 11:20:56.000000000 +0000
+++ ConfigFile.cc
@@ -25,6 +25,7 @@
 ----------------------------------------------------------------------------*/
 
 #include "ConfigFile.h"
+#include <cstdio>
 
 CConfigFile::CConfigFile()
 {
