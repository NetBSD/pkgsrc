$NetBSD: patch-stellarsolver_stellarsolver.cpp,v 1.1 2026/02/17 18:41:01 markd Exp $

No memory_status on OpenBSD or NetBSD

--- stellarsolver/stellarsolver.cpp.orig	2025-05-25 04:36:42.000000000 +0000
+++ stellarsolver/stellarsolver.cpp
@@ -1047,6 +1047,10 @@ bool StellarSolver::getAvailableRAM(doub
     memory = p.readAllStandardOutput();
     totalRAM = memory.toLong() * 1024.0; //It is in kB on this system
     p.close();
+#elif defined(Q_OS_NETBSD)
+    return false;
+#elif defined(Q_OS_OPENBSD)
+    return false;
 #else
     MEMORYSTATUSEX memory_status;
     ZeroMemory(&memory_status, sizeof(MEMORYSTATUSEX));
