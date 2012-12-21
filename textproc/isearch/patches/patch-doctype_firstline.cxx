$NetBSD: patch-doctype_firstline.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers

--- doctype/firstline.cxx~	1997-02-16 23:02:49.000000000 +0000
+++ doctype/firstline.cxx
@@ -112,12 +112,12 @@ Description:	Class FIRSTLINE - TEXT with
 Author:		Edward C. Zimmermann, edz@bsn.com
 @@@-*/
 
-#include <iostream.h>
-#include <stdio.h>
-#include <stdlib.h>
-#include <string.h>
-#include <errno.h>
-#include <ctype.h>
+#include <iostream>
+#include <cstdio>
+#include <cstdlib>
+#include <cstring>
+#include <cerrno>
+#include <cctype>
 #include "isearch.hxx"
 #include "firstline.hxx"
 
