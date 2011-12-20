$NetBSD: patch-src_plan_Node.h,v 1.1 2011/12/20 13:42:48 wiz Exp $

Add missing header.

--- src/plan/Node.h.orig	2006-09-29 20:45:18.000000000 +0000
+++ src/plan/Node.h
@@ -41,7 +41,7 @@
 #ifndef _NODE_H_
 #define _NODE_H_
 
-#include <fstream.h>
+#include <fstream>
 #include <iostream>
 #include <list>
 #include <string>
