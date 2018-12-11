$NetBSD: patch-common_quant.cpp,v 1.1 2018/12/11 17:55:56 jklos Exp $

Use enable512 as a global, not through detect512

--- common/quant.cpp.orig	2018-10-05 12:14:40.000000000 +0000
+++ common/quant.cpp
@@ -723,7 +723,6 @@ uint32_t Quant::rdoQuant(const CUData& c
             X265_CHECK(coeffNum[cgScanPos] == 0, "count of coeff failure\n");
             uint32_t scanPosBase = (cgScanPos << MLS_CG_SIZE);
             uint32_t blkPos      = codeParams.scan[scanPosBase];
-            bool enable512 = detect512();
             if (enable512)
                 primitives.cu[log2TrSize - 2].psyRdoQuant(m_resiDctCoeff, m_fencDctCoeff, costUncoded, &totalUncodedCost, &totalRdCost, &psyScale, blkPos);
             else
@@ -805,8 +804,6 @@ uint32_t Quant::rdoQuant(const CUData& c
             uint32_t blkPos = codeParams.scan[scanPosBase];
             if (usePsyMask)
             {
-                bool enable512 = detect512();
-
                 if (enable512)
                     primitives.cu[log2TrSize - 2].psyRdoQuant(m_resiDctCoeff, m_fencDctCoeff, costUncoded, &totalUncodedCost, &totalRdCost, &psyScale, blkPos);
                 else
