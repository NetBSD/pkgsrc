$NetBSD: patch-src_sat_sat__lookahead.cpp,v 1.1 2022/05/13 10:41:38 jperkin Exp $

Avoid ambiguous function call.

--- src/sat/sat_lookahead.cpp.orig	2018-11-19 20:21:17.000000000 +0000
+++ src/sat/sat_lookahead.cpp
@@ -27,6 +27,8 @@ Notes:
 #include "sat/sat_scc.h"
 #include "util/union_find.h"
 
+using std::pow;
+
 namespace sat {
     lookahead::scoped_ext::scoped_ext(lookahead& p): p(p) {
         if (p.m_s.m_ext) p.m_s.m_ext->set_lookahead(&p); 
