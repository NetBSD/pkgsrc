$NetBSD: patch-src_intlist.hxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers

--- src/intlist.hxx~	2000-02-04 23:39:22.000000000 +0000
+++ src/intlist.hxx
@@ -48,9 +48,9 @@ Author:		Archie Warnock (warnock@clark.n
 #ifndef INTERVALLIST_HXX
 #define INTERVALLIST_HXX
 
-#include <stdlib.h>
-#include <time.h>
-#include <iostream.h>
+#include <cstdlib>
+#include <ctime>
+#include <iostream>
 
 #include "gdt.h"
 #include "defs.hxx"
