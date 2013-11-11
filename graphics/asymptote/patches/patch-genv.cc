$NetBSD: patch-genv.cc,v 1.1 2013/11/11 16:43:21 joerg Exp $

--- genv.cc.orig	2013-11-10 20:25:05.000000000 +0000
+++ genv.cc
@@ -15,7 +15,6 @@
 
 #include <sstream>
 #include <unistd.h>
-#include <bits/stl_algo.h>
 
 #include "genv.h"
 #include "env.h"
