$NetBSD: patch-courier_webmlmd.H,v 1.1 2012/10/26 20:25:19 joerg Exp $

--- courier/webmlmd.H.orig	2012-10-26 15:29:55.000000000 +0000
+++ courier/webmlmd.H
@@ -49,7 +49,7 @@ namespace webmlmd {
 		T t;
 
 		t.reserve(s.size() * 6 / 5);
-		class T::iterator b=s.begin(), e=s.end(), p=b;
+		typename T::iterator b=s.begin(), e=s.end(), p=b;
 
 		while (b != e)
 		{
