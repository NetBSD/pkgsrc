$NetBSD: patch-doctype_iafadoc.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers

--- doctype/iafadoc.cxx~	1996-12-21 00:40:38.000000000 +0000
+++ doctype/iafadoc.cxx
@@ -113,12 +113,12 @@ Description:	Class IAFADOC - IAFA docume
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
 #include "iafadoc.hxx"
 
