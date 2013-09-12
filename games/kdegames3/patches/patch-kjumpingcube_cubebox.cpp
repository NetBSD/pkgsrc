$NetBSD: patch-kjumpingcube_cubebox.cpp,v 1.1 2013/09/12 20:11:30 jperkin Exp $

Avoid "error: call of overloaded <func> is ambiguous"

--- kjumpingcube/cubebox.cpp.orig	2005-10-10 14:56:06.000000000 +0000
+++ kjumpingcube/cubebox.cpp
@@ -194,10 +194,10 @@ double CubeBox::assessField(Player playe
 
    if(player==One)
    {
-      return (int)pow((float)cubesOne,2)+pointsOne-(int)pow(cubesTwo,2)-pointsTwo;
+      return (int)pow((float)cubesOne,2)+pointsOne-(int)pow((float)cubesTwo,2)-pointsTwo;
    }
    else
-      return (int)pow((float)cubesTwo,2)+pointsTwo-(int)pow(cubesOne,2)-pointsOne;
+      return (int)pow((float)cubesTwo,2)+pointsTwo-(int)pow((float)cubesOne,2)-pointsOne;
 
 }
 
