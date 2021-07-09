$NetBSD: patch-lib_programmemory.cpp,v 1.1 2021/07/09 10:50:37 markd Exp $

gcc11 build fix

--- lib/programmemory.cpp.orig	2020-06-13 16:08:37.000000000 +0000
+++ lib/programmemory.cpp
@@ -5,6 +5,7 @@
 #include "symboldatabase.h"
 #include <algorithm>
 #include <cassert>
+#include <limits>
 
 void ProgramMemory::setValue(nonneg int varid, const ValueFlow::Value &value)
 {
