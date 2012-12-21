$NetBSD: patch-doctype_gils.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers

--- doctype/gils.cxx~	1998-11-04 04:50:53.000000000 +0000
+++ doctype/gils.cxx
@@ -40,11 +40,11 @@ Description:	Class GILS - SGML-like Text
 Author:		Archie Warnock, warnock@clark.net
 @@@*/
 
-#include <iostream.h>
-#include <stdio.h>
-#include <stdlib.h>
-#include <string.h>
-#include <errno.h>
+#include <iostream>
+#include <cstdio>
+#include <cstdlib>
+#include <cstring>
+#include <cerrno>
 #include "isearch.hxx"
 #include "gils.hxx"
 
