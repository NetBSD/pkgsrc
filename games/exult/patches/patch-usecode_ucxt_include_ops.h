$NetBSD: patch-usecode_ucxt_include_ops.h,v 1.1 2011/11/25 21:53:26 joerg Exp $

--- usecode/ucxt/include/ops.h.orig	2011-11-25 17:52:40.000000000 +0000
+++ usecode/ucxt/include/ops.h
@@ -19,6 +19,7 @@
 #ifndef OPCODES_H
 #define OPCODES_H
 
+#include <cstdlib>
 #include <map>
 #include <string>
 #include <vector>
