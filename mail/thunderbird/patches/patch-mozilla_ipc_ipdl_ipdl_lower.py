$NetBSD: patch-mozilla_ipc_ipdl_ipdl_lower.py,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/ipc/ipdl/ipdl/lower.py.orig	2013-10-23 22:09:00.000000000 +0000
+++ mozilla/ipc/ipdl/ipdl/lower.py
@@ -1803,7 +1803,7 @@ def _generateMessageClass(md, clsname, m
         StmtExpr(ExprCall(
             ExprVar('StringAppendF'),
             args=[ ExprAddrOf(msgvar),
-                   ExprLiteral.String('[time:%" PRId64 "][%d]'),
+                   ExprLiteral.String('[time:%\\" PRId64 \\"][%d]'),
                    ExprCall(ExprVar('PR_Now')),
                    ExprCall(ExprVar('base::GetCurrentProcId')) ])),
         appendToMsg(pfxvar),
