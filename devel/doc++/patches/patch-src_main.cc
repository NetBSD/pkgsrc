$NetBSD: patch-src_main.cc,v 1.1 2011/11/25 21:38:09 joerg Exp $

--- src/main.cc.orig	2011-11-25 17:20:50.000000000 +0000
+++ src/main.cc
@@ -25,7 +25,7 @@
 #include "config.h"
 
 #include <assert.h>
-#include <fstream.h>
+#include <fstream>
 #include <getopt.h>
 #include <locale.h>
 #include <stdio.h>
