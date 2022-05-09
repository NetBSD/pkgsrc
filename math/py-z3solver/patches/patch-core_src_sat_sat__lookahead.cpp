$NetBSD: patch-core_src_sat_sat__lookahead.cpp,v 1.1 2022/05/09 09:08:27 jperkin Exp $

Avoid ambiguous function calls.

--- core/src/sat/sat_lookahead.cpp.orig	2020-09-11 00:52:41.000000000 +0000
+++ core/src/sat/sat_lookahead.cpp
@@ -26,6 +26,8 @@ Notes:
 #include "sat/sat_scc.h"
 #include "util/union_find.h"
 
+using std::pow;
+
 namespace sat {
     lookahead::scoped_ext::scoped_ext(lookahead& p): p(p) {
         if (p.m_s.m_ext) p.m_s.m_ext->set_lookahead(&p); 
