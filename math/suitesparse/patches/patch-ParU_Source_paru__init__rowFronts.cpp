$NetBSD: patch-ParU_Source_paru__init__rowFronts.cpp,v 1.1 2024/12/19 12:10:36 bacon Exp $

# Fix build on Alma (RHEL) 8

--- ParU/Source/paru_init_rowFronts.cpp.orig	2024-08-24 17:13:32.000000000 +0000
+++ ParU/Source/paru_init_rowFronts.cpp
@@ -34,7 +34,17 @@ ParU_Info paru_init_rowFronts
     ParU_Numeric *Num_handle,
     // inputs, not modified:
     cholmod_sparse *A,
-    const ParU_Symbolic Sym     // symbolic analysis
+    // gcc on Alma 8 actually errors out on line 443:
+    // error: "Sym" is predetermined "shared" for "shared"
+    // It's dumb to error out when the programmer just restates a default,
+    // but some extant versions of gcc do this, while others (and clang)
+    // error out if Sym is not included in the shared list.  Removing
+    // default(none) is risky, as behavior may differ with different
+    // compilers.  Since the code is confirmed to build on most platforms
+    // with const Sym, we know that nothing is trying to modify Sym after,
+    // so removing the const should not cause any problems.
+    // const ParU_Symbolic Sym     // symbolic analysis
+    ParU_Symbolic Sym     // symbolic analysis
 )
 {
 
