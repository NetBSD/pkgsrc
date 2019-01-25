$NetBSD: patch-common_quant.cpp,v 1.2 2019/01/25 09:01:13 adam Exp $

Use enable512 as a global, not through detect512

--- common/quant.cpp.orig	2019-01-23 09:47:18.000000000 +0000
+++ common/quant.cpp
@@ -724,7 +724,6 @@ uint32_t Quant::rdoQuant(const CUData& c
             uint32_t scanPosBase = (cgScanPos << MLS_CG_SIZE);
             uint32_t blkPos      = codeParams.scan[scanPosBase];
 #if X265_ARCH_X86
-            bool enable512 = detect512();
             if (enable512)
                 primitives.cu[log2TrSize - 2].psyRdoQuant(m_resiDctCoeff, m_fencDctCoeff, costUncoded, &totalUncodedCost, &totalRdCost, &psyScale, blkPos);
             else
@@ -811,7 +810,6 @@ uint32_t Quant::rdoQuant(const CUData& c
             if (usePsyMask)
             {
 #if X265_ARCH_X86
-                bool enable512 = detect512();
                 if (enable512)
                     primitives.cu[log2TrSize - 2].psyRdoQuant(m_resiDctCoeff, m_fencDctCoeff, costUncoded, &totalUncodedCost, &totalRdCost, &psyScale, blkPos);
                 else
