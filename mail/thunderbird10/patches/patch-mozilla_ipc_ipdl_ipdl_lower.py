$NetBSD: patch-mozilla_ipc_ipdl_ipdl_lower.py,v 1.1 2013/08/29 12:57:35 joerg Exp $

--- mozilla/ipc/ipdl/ipdl/lower.py.orig	2013-01-05 14:22:10.000000000 +0000
+++ mozilla/ipc/ipdl/ipdl/lower.py
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
