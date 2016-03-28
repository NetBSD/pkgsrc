$NetBSD: patch-tools_lldb-mi_MIDriver.cpp,v 1.1 2016/03/28 13:13:55 kamil Exp $

Cannot pass object of non-trivial type 'const CMIUtilString'
through variadic function.

--- tools/lldb-mi/MIDriver.cpp.orig	2016-02-21 02:08:07.000000000 +0000
+++ tools/lldb-mi/MIDriver.cpp
@@ -491,7 +491,7 @@ CMIDriver::StartWorkerThreads()
     {
         const CMIUtilString errMsg = CMIUtilString::Format(MIRSRC(IDS_THREADMGR_ERR_THREAD_FAIL_CREATE),
                                                            CMICmnThreadMgrStd::Instance().GetErrorDescription().c_str());
-        SetErrorDescriptionn(errMsg);
+        SetErrorDescriptionn(errMsg.c_str());
         return MIstatus::failure;
     }
 
