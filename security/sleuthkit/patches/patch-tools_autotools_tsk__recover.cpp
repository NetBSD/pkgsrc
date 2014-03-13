$NetBSD: patch-tools_autotools_tsk__recover.cpp,v 1.2 2014/03/13 23:41:31 pettai Exp $

needs limits.h for PATH_MAX

--- tools/autotools/tsk_recover.cpp.orig	2014-03-13 23:04:47.000000000 +0000
+++ tools/autotools/tsk_recover.cpp
@@ -9,6 +9,7 @@
  **
  */
 
+#include "limits.h"
 #include "tsk/tsk_tools_i.h"
 #include <locale.h>
 #include <sys/stat.h>
