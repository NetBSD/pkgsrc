$NetBSD: patch-tools_lldb-mi_MIDriver.cpp,v 1.2 2017/03/17 22:38:17 adam Exp $

Cannot pass object of non-trivial type 'const CMIUtilString'
through variadic function.

--- tools/lldb-mi/MIDriver.cpp.orig	2016-09-12 07:14:51.000000000 +0000
+++ tools/lldb-mi/MIDriver.cpp
@@ -509,7 +509,7 @@ bool CMIDriver::StartWorkerThreads() {
     const CMIUtilString errMsg = CMIUtilString::Format(
         MIRSRC(IDS_THREADMGR_ERR_THREAD_FAIL_CREATE),
         CMICmnThreadMgrStd::Instance().GetErrorDescription().c_str());
-    SetErrorDescriptionn(errMsg);
+    SetErrorDescriptionn(errMsg.c_str());
     return MIstatus::failure;
   }
 
