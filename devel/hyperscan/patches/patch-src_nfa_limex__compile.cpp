$NetBSD: patch-src_nfa_limex__compile.cpp,v 1.1 2018/08/17 16:03:20 minskim Exp $

Make this file compile with Boost 1.68.0.

--- src/nfa/limex_compile.cpp.orig	2018-07-09 16:45:44.000000000 +0000
+++ src/nfa/limex_compile.cpp
@@ -980,7 +980,7 @@ u32 addSquashMask(const build_info &args
     // see if we've already seen it, otherwise add a new one.
     auto it = find(squash.begin(), squash.end(), sit->second);
     if (it != squash.end()) {
-        return verify_u32(distance(squash.begin(), it));
+        return verify_u32(std::distance(squash.begin(), it));
     }
     u32 idx = verify_u32(squash.size());
     squash.push_back(sit->second);
