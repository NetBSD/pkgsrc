$NetBSD: patch-noatun-plugins_noatunmadness_madness.cpp,v 1.1 2014/07/14 09:15:09 jperkin Exp $

Avoid "error: call of overloaded <func> is ambiguous"

--- noatun-plugins/noatunmadness/madness.cpp.orig	2008-02-13 09:35:41.000000000 +0000
+++ noatun-plugins/noatunmadness/madness.cpp
@@ -71,7 +71,7 @@ void Madness::scopeEvent(float *d, int s
 	int delta=0; // in pixels
 	for (int count=0; count<size; count++)
 	{
-		delta+=(int)((log10(d[count]+1)/log(2))*(size-count))/2;
+		delta+=(int)((log10(d[count]+1)/log(2.0))*(size-count))/2;
 	}
 	
 //	cout << "delta: " << delta << endl;
