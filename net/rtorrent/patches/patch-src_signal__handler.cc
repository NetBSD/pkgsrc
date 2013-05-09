$NetBSD: patch-src_signal__handler.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/signal_handler.cc.orig	2013-05-03 23:09:48.000000000 +0000
+++ src/signal_handler.cc
@@ -38,6 +38,7 @@
 
 #include <signal.h>
 #include <stdexcept>
+#include <string>
 #include "rak/error_number.h"
 #include "signal_handler.h"
 
