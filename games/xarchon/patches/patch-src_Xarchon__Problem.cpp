$NetBSD: patch-src_Xarchon__Problem.cpp,v 1.1 2011/11/27 19:42:25 joerg Exp $

--- src/Xarchon_Problem.cpp.orig	2011-11-27 02:30:20.000000000 +0000
+++ src/Xarchon_Problem.cpp
@@ -1,5 +1,6 @@
 #include "Xarchon_Problem.hpp"
 #include "Xarchon_Interface.hpp"
+#include <cstring>
 
 Xarchon_State::Xarchon_State(void) 
 {
