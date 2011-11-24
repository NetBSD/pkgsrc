$NetBSD: patch-encfs_ConfigVar.cpp,v 1.1 2011/11/24 14:11:19 joerg Exp $

--- encfs/ConfigVar.cpp.orig	2011-11-24 00:20:59.000000000 +0000
+++ encfs/ConfigVar.cpp
@@ -17,6 +17,7 @@
 
 #include "ConfigVar.h"
 #include <rlog/rlog.h>
+#include <string.h>
 
 using namespace rlog;
 
