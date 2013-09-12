$NetBSD: patch-kjumpingcube_brain.cpp,v 1.1 2013/09/12 20:11:30 jperkin Exp $

Avoid "error: call of overloaded <func> is ambiguous"

--- kjumpingcube/brain.cpp.orig	2005-10-10 14:56:06.000000000 +0000
+++ kjumpingcube/brain.cpp
@@ -108,7 +108,7 @@ bool Brain::getHint(int& row, int& colum
       worth[i]=new double[box.dim()];
 
    // alle Werte auf kleinstmöglichen Wert setzen
-   double min=-pow(2.0,sizeof(long int)*8-1);  // Maximum auf kleinst möglichen Wert setzen
+   double min=-pow(2.0,(float)sizeof(long int)*8-1);  // Maximum auf kleinst möglichen Wert setzen
 
    for(i=0;i<box.dim();i++)
      for(j=0;j<box.dim();j++)
