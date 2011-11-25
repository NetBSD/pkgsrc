$NetBSD: patch-lib3d_dimension.C,v 1.1 2011/11/25 21:50:31 joerg Exp $

--- lib3d/dimension.C.orig	2011-11-25 15:15:48.000000000 +0000
+++ lib3d/dimension.C
@@ -3,10 +3,10 @@
 // it under the terms of the GNU General Public License v2 or later.
 
 
-#include <iostream.h>
+#include <iostream>
 #include "dimension.h"
 
-
+using namespace std;
 
 /************************************************************************/
 ostream& operator<<(ostream& out, const dimension& d) {
