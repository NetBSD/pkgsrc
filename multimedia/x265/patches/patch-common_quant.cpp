$NetBSD: patch-common_quant.cpp,v 1.4 2024/04/05 13:45:50 ryoon Exp $

Use enable512 as a global, not through detect512

--- common/quant.cpp.orig	2024-04-05 09:11:03.482354127 +0000
+++ common/quant.cpp
@@ -708,7 +708,6 @@ uint32_t Quant::rdoQuant(const CUData& c
             uint32_t scanPosBase = (cgScanPos << MLS_CG_SIZE);
             uint32_t blkPos      = codeParams.scan[scanPosBase];
 #if X265_ARCH_X86
-            bool enable512 = detect512();
             if (enable512)
                 primitives.cu[log2TrSize - 2].psyRdoQuant(m_resiDctCoeff, m_fencDctCoeff, costUncoded, &totalUncodedCost, &totalRdCost, &psyScale, blkPos);
             else
@@ -795,7 +794,6 @@ uint32_t Quant::rdoQuant(const CUData& c
             if (usePsyMask)
             {
 #if X265_ARCH_X86
-                bool enable512 = detect512();
                 if (enable512)
                     primitives.cu[log2TrSize - 2].psyRdoQuant(m_resiDctCoeff, m_fencDctCoeff, costUncoded, &totalUncodedCost, &totalRdCost, &psyScale, blkPos);
                 else
