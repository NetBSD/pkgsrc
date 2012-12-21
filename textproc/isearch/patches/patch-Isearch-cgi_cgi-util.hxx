$NetBSD: patch-Isearch-cgi_cgi-util.hxx,v 1.1 2012/12/21 10:29:46 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers

--- Isearch-cgi/cgi-util.hxx~	1998-05-12 16:48:06.000000000 +0000
+++ Isearch-cgi/cgi-util.hxx
@@ -47,9 +47,9 @@ Authors:        Kevin Gamiel, kgamiel@cn
 #define _CGIUTIL_HXX
 
 #include "gdt.h"
-#include <stdio.h>
-#include <stdlib.h>
-#include <iostream.h>
+#include <cstdio>
+#include <cstdlib>
+#include <iostream>
 
 #define CGI_MAXENTRIES 100
 #define POST 0
