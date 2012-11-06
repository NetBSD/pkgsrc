$NetBSD: patch-ConfigFile.cc,v 1.2 2012/11/06 18:38:34 drochner Exp $

--- ConfigFile.cc.orig	2012-10-19 21:40:21.000000000 +0000
+++ ConfigFile.cc
@@ -27,6 +27,7 @@
 ----------------------------------------------------------------------------*/
 
 #include "ConfigFile.h"
+#include <cstdio>
 
 #include <stdio.h>
 #include <strings.h>
