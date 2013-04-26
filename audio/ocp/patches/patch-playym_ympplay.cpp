$NetBSD: patch-playym_ympplay.cpp,v 1.1 2013/04/26 17:39:23 shattered Exp $

--- playym/ympplay.cpp.orig	2011-11-17 21:46:08.000000000 +0000
+++ playym/ympplay.cpp
@@ -110,7 +110,7 @@ static char convnote(long freq)
 
 	float frfac=(float)freq/220.0;
 
-	float nte=12*(log(frfac)/log(2))+48;
+	float nte=12*(log(frfac)/log(2.0))+48;
 
 	if (nte<0 || nte>127) nte=0xff;
 	return (char)nte;
