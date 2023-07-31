$NetBSD: patch-bamSortByCoordinate.cpp,v 1.1 2023/07/31 14:34:18 bacon Exp $

# Portability

--- bamSortByCoordinate.cpp.orig	2022-11-01 14:50:35.000000000 +0000
+++ bamSortByCoordinate.cpp
@@ -69,7 +69,7 @@ void bamSortByCoordinate (Parameters &P,
                             boolWait=false;
                             totalMem+=newMem;
                         };
-                        sleep(0.1);
+                        usleep(100000);
                     };
                     BAMbinSortByCoordinate(ibin,binN,binS,P.runThreadN,P.outBAMsortTmpDir, P, genome, solo);
                     #pragma omp critical
