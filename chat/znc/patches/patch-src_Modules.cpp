$NetBSD: patch-src_Modules.cpp,v 1.1 2019/06/18 10:21:37 nia Exp $

Fix CVE-2019-12816

https://github.com/znc/znc/commit/8de9e376ce531fe7f3c8b0aa4876d15b479b7311

--- src/Modules.cpp.orig	2019-03-30 14:37:00.000000000 +0000
+++ src/Modules.cpp
@@ -1624,11 +1624,30 @@ CModule* CModules::FindModule(const CStr
     return nullptr;
 }
 
+bool CModules::ValidateModuleName(const CString& sModule, CString& sRetMsg) {
+    for (unsigned int a = 0; a < sModule.length(); a++) {
+        if (((sModule[a] < '0') || (sModule[a] > '9')) &&
+            ((sModule[a] < 'a') || (sModule[a] > 'z')) &&
+            ((sModule[a] < 'A') || (sModule[a] > 'Z')) && (sModule[a] != '_')) {
+            sRetMsg =
+                t_f("Module names can only contain letters, numbers and "
+                    "underscores, [{1}] is invalid")(sModule);
+            return false;
+        }
+    }
+
+    return true;
+}
+
 bool CModules::LoadModule(const CString& sModule, const CString& sArgs,
                           CModInfo::EModuleType eType, CUser* pUser,
                           CIRCNetwork* pNetwork, CString& sRetMsg) {
     sRetMsg = "";
 
+    if (!ValidateModuleName(sModule, sRetMsg)) {
+        return false;
+    }
+
     if (FindModule(sModule) != nullptr) {
         sRetMsg = t_f("Module {1} already loaded.")(sModule);
         return false;
@@ -1781,6 +1800,10 @@ bool CModules::ReloadModule(const CStrin
 
 bool CModules::GetModInfo(CModInfo& ModInfo, const CString& sModule,
                           CString& sRetMsg) {
+    if (!ValidateModuleName(sModule, sRetMsg)) {
+        return false;
+    }
+
     CString sModPath, sTmp;
 
     bool bSuccess;
@@ -1799,6 +1822,10 @@ bool CModules::GetModInfo(CModInfo& ModI
 
 bool CModules::GetModPathInfo(CModInfo& ModInfo, const CString& sModule,
                               const CString& sModPath, CString& sRetMsg) {
+    if (!ValidateModuleName(sModule, sRetMsg)) {
+        return false;
+    }
+
     ModInfo.SetName(sModule);
     ModInfo.SetPath(sModPath);
 
@@ -1911,15 +1938,8 @@ ModHandle CModules::OpenModule(const CSt
     // Some sane defaults in case anything errors out below
     sRetMsg.clear();
 
-    for (unsigned int a = 0; a < sModule.length(); a++) {
-        if (((sModule[a] < '0') || (sModule[a] > '9')) &&
-            ((sModule[a] < 'a') || (sModule[a] > 'z')) &&
-            ((sModule[a] < 'A') || (sModule[a] > 'Z')) && (sModule[a] != '_')) {
-            sRetMsg =
-                t_f("Module names can only contain letters, numbers and "
-                    "underscores, [{1}] is invalid")(sModule);
-            return nullptr;
-        }
+    if (!ValidateModuleName(sModule, sRetMsg)) {
+        return nullptr;
     }
 
     // The second argument to dlopen() has a long history. It seems clear
