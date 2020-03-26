$NetBSD: patch-src_expr.cpp,v 1.1 2020/03/26 02:35:31 joerg Exp $

--- src/expr.cpp.orig	2020-03-26 02:01:18.613760749 +0000
+++ src/expr.cpp
@@ -14,12 +14,10 @@
 
 #line 1 "expr.y"
 
-namespace std {  
 #include <stdio.h>
 #include <memory.h>
 #include <stdlib.h>
 #include <string.h>
-}
 
 using namespace std;
  
