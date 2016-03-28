$NetBSD: patch-tools_lldb-mi_MIUtilParse.h,v 1.1 2016/03/28 13:13:55 kamil Exp $

--- tools/lldb-mi/MIUtilParse.h.orig	2015-12-06 02:57:30.000000000 +0000
+++ tools/lldb-mi/MIUtilParse.h
@@ -9,8 +9,7 @@
  
 #pragma once
  
-// Third party headers:
-#include "../lib/Support/regex_impl.h"
+#include "lldb/Utility/regex_impl.h"
 
 // In-house headers:
 #include "MIUtilString.h"
