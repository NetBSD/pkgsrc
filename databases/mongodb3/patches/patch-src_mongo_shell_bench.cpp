$NetBSD: patch-src_mongo_shell_bench.cpp,v 1.1 2019/06/28 16:30:56 gdt Exp $

--- src/mongo/shell/bench.cpp.orig	2017-07-11 16:39:09.026014232 +0000
+++ src/mongo/shell/bench.cpp
@@ -34,6 +34,7 @@
 
 #include "mongo/shell/bench.h"
 
+#include <string>
 #include <iostream>
 #include <pcrecpp.h>
 
@@ -78,6 +79,7 @@ namespace mongo {
 using std::unique_ptr;
 using std::cout;
 using std::map;
+using std::string;
 
 const std::map<OpType, std::string> opTypeName{{OpType::NONE, "none"},
                                                {OpType::NOP, "nop"},
