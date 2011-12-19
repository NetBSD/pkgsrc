$NetBSD: patch-src_operator.cc,v 1.1 2011/12/19 15:58:40 wiz Exp $

--- src/operator.cc.orig	2005-08-31 14:48:18.000000000 +0000
+++ src/operator.cc
@@ -1,4 +1,5 @@
 #include <iostream>
+#include <typeinfo>
 
 #include "operator.h"
 #include "errors.h"
