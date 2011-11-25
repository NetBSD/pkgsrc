$NetBSD: patch-src_doc2tex.ll,v 1.1 2011/11/25 21:38:09 joerg Exp $

--- src/doc2tex.ll.orig	2011-11-25 17:20:38.000000000 +0000
+++ src/doc2tex.ll
@@ -23,8 +23,8 @@
 
 %{
 #include <assert.h>
-#include <fstream.h>
-#include <iostream.h>
+#include <fstream>
+#include <iostream>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -33,6 +33,8 @@
 #include "classgraph.h"
 #include "doc.h"
 
+using namespace std;
+
 #define YY_DECL int yylex()
 
 #undef	YY_INPUT
