$NetBSD: patch-log__proc.h,v 1.1 2011/11/24 14:08:05 joerg Exp $

--- log_proc.h.orig	2011-11-24 01:12:41.000000000 +0000
+++ log_proc.h
@@ -25,6 +25,7 @@
 #include <string>
 #include <fstream>
 #include <iomanip>
+#include <cstdlib>
 
 #include "board.h"
 #include "order.h"
