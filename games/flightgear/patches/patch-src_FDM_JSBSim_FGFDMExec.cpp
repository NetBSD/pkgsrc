$NetBSD: patch-src_FDM_JSBSim_FGFDMExec.cpp,v 1.1 2017/02/08 00:03:30 joerg Exp $

--- src/FDM/JSBSim/FGFDMExec.cpp.orig	2017-01-09 15:19:01.104940701 +0000
+++ src/FDM/JSBSim/FGFDMExec.cpp
@@ -188,7 +188,7 @@ FGFDMExec::~FGFDMExec()
 
   PropertyCatalog.clear();
 
-  if (FDMctr > 0) (*FDMctr)--;
+  if (FDMctr) (*FDMctr)--;
 
   Debug(1);
 }
