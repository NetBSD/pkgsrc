$NetBSD: patch-gnuradio-runtime_lib_pmt_pmt__serialize.cc,v 1.1 2020/04/17 13:33:44 joerg Exp $

--- gnuradio-runtime/lib/pmt/pmt_serialize.cc.orig	2020-04-17 00:28:42.316619809 +0000
+++ gnuradio-runtime/lib/pmt/pmt_serialize.cc
@@ -23,6 +23,7 @@
 #include <config.h>
 #endif
 
+#include <sstream>
 #include <vector>
 #include <pmt/pmt.h>
 #include "pmt_int.h"
