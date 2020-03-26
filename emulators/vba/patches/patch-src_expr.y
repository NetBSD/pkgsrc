$NetBSD: patch-src_expr.y,v 1.1 2020/03/26 02:35:31 joerg Exp $

--- src/expr.y.orig	2020-03-26 02:00:05.333831596 +0000
+++ src/expr.y
@@ -1,10 +1,8 @@
 %{
-namespace std {  
 #include <stdio.h>
 #include <memory.h>
 #include <stdlib.h>
 #include <string.h>
-}
 
 using namespace std;
  
