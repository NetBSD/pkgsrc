$NetBSD: patch-src_signal__handler.cc,v 1.3 2013/09/18 16:33:09 joerg Exp $

--- src/signal_handler.cc.orig	2012-03-29 13:06:11.000000000 +0000
+++ src/signal_handler.cc
@@ -38,6 +38,7 @@
 
 #include <signal.h>
 #include <stdexcept>
+#include <string>
 #include "rak/error_number.h"
 #include "signal_handler.h"
 
