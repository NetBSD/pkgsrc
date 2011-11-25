$NetBSD: patch-common_UCvsConsole.cpp,v 1.1 2011/11/25 21:42:44 joerg Exp $

--- common/UCvsConsole.cpp.orig	2011-11-25 17:57:07.000000000 +0000
+++ common/UCvsConsole.cpp
@@ -22,6 +22,7 @@
  * 
  */
 
+#include <cstdlib>
 #include "stdafx.h"
 
 #if qGTK
