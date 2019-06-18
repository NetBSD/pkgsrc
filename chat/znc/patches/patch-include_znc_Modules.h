$NetBSD: patch-include_znc_Modules.h,v 1.1 2019/06/18 10:21:37 nia Exp $

Fix CVE-2019-12816

https://github.com/znc/znc/commit/8de9e376ce531fe7f3c8b0aa4876d15b479b7311

--- include/znc/Modules.h.orig	2019-03-30 14:37:00.000000000 +0000
+++ include/znc/Modules.h
@@ -1600,6 +1600,7 @@ class CModules : public std::vector<CMod
   private:
     static ModHandle OpenModule(const CString& sModule, const CString& sModPath,
                                 CModInfo& Info, CString& sRetMsg);
+    static bool ValidateModuleName(const CString& sModule, CString& sRetMsg);
 
   protected:
     CUser* m_pUser;
