$NetBSD: patch-tochnog.h,v 1.1 2011/11/24 13:50:50 joerg Exp $

--- tochnog.h.orig	2011-11-22 18:27:38.000000000 +0000
+++ tochnog.h
@@ -17,22 +17,26 @@
     Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
 
-#include <iostream.h>
 #include <assert.h>
 #include <ctype.h>
 #include <float.h>
-#include <fstream.h>
-#include <iomanip.h>
 #include <math.h>
 #include <limits.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
+
+#include <iostream>
+#include <fstream>
+#include <iomanip>
+
 #include "tnpetsc.h"
 #include "tnsuplu.h"
 #include "tnhypo.h"
 
+using namespace std;
+
 typedef long int integer;
 typedef double doublereal;       
 
