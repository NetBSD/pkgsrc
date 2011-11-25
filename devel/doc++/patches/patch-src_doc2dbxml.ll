$NetBSD: patch-src_doc2dbxml.ll,v 1.1 2011/11/25 21:38:09 joerg Exp $

--- src/doc2dbxml.ll.orig	2011-11-25 17:19:02.000000000 +0000
+++ src/doc2dbxml.ll
@@ -25,12 +25,14 @@
 
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
 
