$NetBSD: patch-mozilla_js_src_vm_SPSProfiler.cpp,v 1.1 2014/07/27 05:36:07 ryoon Exp $

--- mozilla/js/src/vm/SPSProfiler.cpp.orig	2013-10-23 22:09:05.000000000 +0000
+++ mozilla/js/src/vm/SPSProfiler.cpp
@@ -8,6 +8,7 @@
 
 #include "jsnum.h"
 #include "jsscript.h"
+#include "jscntxtinlines.h"
 
 #include "vm/SPSProfiler.h"
 #include "vm/StringBuffer.h"
