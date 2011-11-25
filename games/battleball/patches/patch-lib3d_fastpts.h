$NetBSD: patch-lib3d_fastpts.h,v 1.1 2011/11/25 21:50:31 joerg Exp $

--- lib3d/fastpts.h.orig	2011-11-25 15:13:50.000000000 +0000
+++ lib3d/fastpts.h
@@ -7,12 +7,13 @@
 #define FASTPTS_h
 
 
-#include <iostream.h>
+#include <iostream>
 #include "general.h"
 #include "table.h"
 #include "xform.h"
 #include "dimentable.h"
 
+using namespace std;
 
 /*=========================================================================*/
 struct pt3dPtr {
@@ -70,7 +71,7 @@ struct FastPts {
   int	Num() const		{return pts.Num();}
   pnt	*Array() const		{return pts.Array();}
   pnt&	operator[](int i) const	{return pts[i];}
-  table<pnt>& table()		{return pts;}
+  table<pnt>& my_table()	{return pts;}
 };
 
 #ifdef FASTPTS_TEMPLATE
