$NetBSD: patch-ipc_ipdl_ipdl_lower.py,v 1.1 2013/08/29 12:56:15 joerg Exp $

--- ipc/ipdl/ipdl/lower.py.orig	2013-08-28 14:34:56.000000000 +0000
+++ ipc/ipdl/ipdl/lower.py
@@ -3367,7 +3367,7 @@ class _GenerateProtocolActorCode(ipdl.as
             # SharedMemory* CreateSharedMemory(size, type, bool, id_t*):
             #   nsAutoPtr<SharedMemory> seg(Shmem::Alloc(size, type, unsafe));
             #   if (!shmem)
-            #     return false
+            #     return null;
             #   Shmem s(seg, [nextshmemid]);
             #   Message descriptor;
             #   if (!s->ShareTo(subprocess, mId, descriptor) ||
@@ -3395,7 +3395,7 @@ class _GenerateProtocolActorCode(ipdl.as
                                             p.routingId()))
             ])
             failif = StmtIf(ExprNot(descriptorvar))
-            failif.addifstmt(StmtReturn.FALSE)
+            failif.addifstmt(StmtReturn(ExprLiteral.NULL))
             createshmem.addstmt(failif)
 
             failif = StmtIf(ExprNot(ExprCall(
