$NetBSD: patch-book.cc,v 1.1 2011/11/24 14:08:05 joerg Exp $

--- book.cc.orig	2011-11-24 01:11:40.000000000 +0000
+++ book.cc
@@ -25,6 +25,7 @@
 #include "rand.h"
 #include "gtstream.h"
 
+#include <cstdlib>
 #include <vector>
 #include <iostream>
 #include <stdexcept>
