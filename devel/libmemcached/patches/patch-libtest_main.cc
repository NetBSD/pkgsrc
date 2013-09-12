$NetBSD: patch-libtest_main.cc,v 1.1 2013/09/12 14:20:56 fhajny Exp $

strings.h needed for rindex.
--- libtest/main.cc.orig	2013-04-03 04:22:00.000000000 +0000
+++ libtest/main.cc
@@ -45,6 +45,7 @@
 #include <iostream>
 #include <fstream>
 #include <memory>
+#include <strings.h>
 #include <sys/stat.h>
 #include <sys/time.h>
 #include <sys/types.h>
