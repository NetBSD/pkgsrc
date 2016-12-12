$NetBSD: patch-variables.cpp,v 1.1 2016/12/12 06:21:47 dholland Exp $

Avoid undefined behavior.

--- variables.cpp~	2002-10-17 21:53:00.000000000 +0000
+++ variables.cpp
@@ -453,6 +453,7 @@ char* GlaxiumVariables::getFullOptionsPa
 	static char strReturn[1024];
 	strcpy(strReturn, getenv("HOME"));
 	strcat(strReturn, "/.glaxiumrc");
+	return strReturn;
 #endif
 }
 
