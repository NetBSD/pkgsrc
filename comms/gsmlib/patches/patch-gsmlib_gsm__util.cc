$NetBSD: patch-gsmlib_gsm__util.cc,v 1.1 2012/02/16 17:17:08 hans Exp $

--- gsmlib/gsm_util.cc.orig	2002-09-22 15:41:08.000000000 +0200
+++ gsmlib/gsm_util.cc	2012-01-25 19:58:53.702987952 +0100
@@ -37,6 +37,7 @@
 #endif
 #include <stdio.h>
 #include <sys/stat.h>
+#include <stdlib.h>
 
 using namespace std;
 using namespace gsmlib;
