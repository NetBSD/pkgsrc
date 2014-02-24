$NetBSD: patch-tools_autotools_tsk__recover.cpp,v 1.1 2014/02/24 13:10:12 wiedi Exp $

needs limits.h for PATH_MAX
--- tools/autotools/tsk_recover.cpp.orig	2011-10-07 19:12:29.000000000 +0000
+++ tools/autotools/tsk_recover.cpp
@@ -9,6 +9,7 @@
  **
  */
 
+#include <limits.h>
 #include "tsk3/tsk_tools_i.h"
 #include <locale.h>
 #include <sys/stat.h>
