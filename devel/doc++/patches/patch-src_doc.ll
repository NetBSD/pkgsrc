$NetBSD: patch-src_doc.ll,v 1.1 2011/11/25 21:38:09 joerg Exp $

--- src/doc.ll.orig	2011-11-25 17:18:47.000000000 +0000
+++ src/doc.ll
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
