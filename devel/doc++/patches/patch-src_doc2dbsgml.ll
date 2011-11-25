$NetBSD: patch-src_doc2dbsgml.ll,v 1.1 2011/11/25 21:38:09 joerg Exp $

--- src/doc2dbsgml.ll.orig	2011-11-25 17:19:15.000000000 +0000
+++ src/doc2dbsgml.ll
@@ -22,12 +22,14 @@
 
 %{
 #include <assert.h>
-#include <fstream.h>
-#include <iostream.h>
+#include <fstream>
+#include <iostream>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
+using namespace std;
+
 #include "classgraph.h"
 #include "doc.h"
 
