$NetBSD: patch-src_codex.cpp,v 1.1.1.1 2012/01/08 15:52:12 wiz Exp $

Add missing header.

--- src/codex.cpp.orig	2005-09-06 06:21:15.000000000 +0000
+++ src/codex.cpp
@@ -21,6 +21,7 @@
 #include "u4.h"
 #include "u4file.h"
 #include "utils.h"
+#include <string.h>
 
 using namespace std;
 
