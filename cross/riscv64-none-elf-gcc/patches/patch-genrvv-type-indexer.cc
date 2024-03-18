$NetBSD: patch-genrvv-type-indexer.cc,v 1.1 2024/03/18 17:39:35 dogcow Exp $

Fixes: https://gitlab.com/buildroot.org/toolchains-builder/-/jobs/4202276589

diff --git a/gcc/config/riscv/genrvv-type-indexer.cc b/gcc/config/riscv/genrvv-type-indexer.cc
index e677b55290c..eebe382d1c3 100644
--- gcc/config/riscv/genrvv-type-indexer.cc.orig
+++ gcc/config/riscv/genrvv-type-indexer.cc
@@ -115,9 +115,9 @@ same_ratio_eew_type (unsigned sew, int lmul_log2, unsigned eew, bool unsigned_p,
   if (sew == eew)
     elmul_log2 = lmul_log2;
   else if (sew > eew)
-    elmul_log2 = lmul_log2 - std::log2 (sew / eew);
+    elmul_log2 = lmul_log2 - log2 (sew / eew);
   else /* sew < eew */
-    elmul_log2 = lmul_log2 + std::log2 (eew / sew);
+    elmul_log2 = lmul_log2 + log2 (eew / sew);
 
   if (float_p)
     return floattype (eew, elmul_log2);
-- 
2.39.3

