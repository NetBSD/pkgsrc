$NetBSD: patch-common_UCvsConsole.cpp,v 1.2 2012/12/20 22:00:42 joerg Exp $

--- common/UCvsConsole.cpp.orig	2000-06-06 05:48:24.000000000 +0000
+++ common/UCvsConsole.cpp
@@ -22,6 +22,7 @@
  * 
  */
 
+#include <cstdlib>
 #include "stdafx.h"
 
 #if qGTK
@@ -230,7 +231,7 @@ extern "C"
 			nEndChar = w.selection_end_pos;
 		}
 		
-		guint long length = nEndChar - nStartChar;
+		size_t length = nEndChar - nStartChar;
 		if(length > 0 && nStartChar < len)
 		{			
 			char *buf = (char *)malloc((length + 1) * sizeof(char));
