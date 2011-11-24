$NetBSD: patch-gen__book.cc,v 1.1 2011/11/24 14:08:05 joerg Exp $

--- gen_book.cc.orig	2011-11-24 01:15:36.000000000 +0000
+++ gen_book.cc
@@ -20,6 +20,7 @@
 
 #include "config.h"
 
+#include <cstring>
 #include <fstream>
 #include <sstream>
 
