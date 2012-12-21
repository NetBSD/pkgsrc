$NetBSD: patch-doctype_fgdcsite.cxx,v 1.1 2012/12/21 10:29:46 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - open the std namespace instead of using explicit "std" qualification

--- doctype/fgdcsite.cxx~	1998-11-04 04:50:53.000000000 +0000
+++ doctype/fgdcsite.cxx
@@ -42,15 +42,17 @@ Description:	Class FGDCSITE - for FGDC N
 Author:		Kevin Gamiel, Kevin.Gamiel@cnidr.org
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
 #include "sgmltag.hxx"
 #include "fgdcsite.hxx"
 
+using namespace std;
+
 FGDCSITE::FGDCSITE(PIDBOBJ DbParent) 
   : SGMLTAG(DbParent) 
 {
