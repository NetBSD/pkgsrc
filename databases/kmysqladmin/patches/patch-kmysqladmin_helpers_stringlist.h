$NetBSD: patch-kmysqladmin_helpers_stringlist.h,v 1.1 2011/11/24 14:16:18 joerg Exp $

--- kmysqladmin/helpers/stringlist.h.orig	2011-11-24 01:52:27.000000000 +0000
+++ kmysqladmin/helpers/stringlist.h
@@ -25,6 +25,7 @@
 #include "stringhelper.h"
 #include <vector>
 #include <string>
+#include <algorithm>
 
 /*!
  * Implementation of a string-list
