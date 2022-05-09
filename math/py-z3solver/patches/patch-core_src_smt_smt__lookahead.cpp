$NetBSD: patch-core_src_smt_smt__lookahead.cpp,v 1.1 2022/05/09 09:08:27 jperkin Exp $

Avoid ambiguous function calls.

--- core/src/smt/smt_lookahead.cpp.orig	2020-09-11 00:52:41.000000000 +0000
+++ core/src/smt/smt_lookahead.cpp
@@ -23,6 +23,8 @@ Revision History:
 #include "smt/smt_lookahead.h"
 #include "smt/smt_context.h"
 
+using std::pow;
+
 namespace smt {
 
     lookahead::lookahead(context& ctx): 
