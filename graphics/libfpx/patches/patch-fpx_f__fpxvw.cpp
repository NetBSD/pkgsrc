$NetBSD: patch-fpx_f__fpxvw.cpp,v 1.1.2.2 2017/10/05 02:08:51 spz Exp $
Fix CVE-2017-12921
--- fpx/f_fpxvw.cpp.orig	2017-10-04 10:25:20.000000000 +0000
+++ fpx/f_fpxvw.cpp
@@ -775,27 +775,67 @@ Boolean PFileFlashPixView::WriteCompObj(
 // Get property in summary info property set
 Boolean PFileFlashPixView::GetSummaryInfoProperty (DWORD pID, OLEProperty ** res)
 {
-  return summaryInfoPropertySet->GetProperty(pID, res);
+  Boolean ok = TRUE;
+
+  // If absent, there is an error
+  if (summaryInfoPropertySet == NULL)
+    ok = FALSE;
+
+  // Get the property
+  if (ok)
+    ok = summaryInfoPropertySet->GetProperty(pID, res);
+
+  return ok;
 }
 
 // Set property in summary info property set
 Boolean PFileFlashPixView::SetSummaryInfoProperty (DWORD pID, DWORD propType, OLEProperty ** res)
 {
-  return summaryInfoPropertySet->NewProperty(pID, propType, res);
+  Boolean ok = TRUE;
+
+  // If absent, there is an error
+  if (summaryInfoPropertySet == NULL)
+    ok = FALSE;
+
+  // Get the property
+  if (ok)
+    ok = summaryInfoPropertySet->NewProperty(pID, propType, res);
+
+  return ok;
 }
 
 
 // Get property in global info property set
 Boolean PFileFlashPixView::GetGlobalInfoProperty (DWORD pID, OLEProperty ** res)
 {
-  return globalInfoPropertySet->GetProperty(pID, res);
+  Boolean ok = TRUE;
+
+  // If absent, there is an error
+  if (globalInfoPropertySet == NULL)
+    ok = FALSE;
+
+  // Get the property
+  if (ok)
+    ok = globalInfoPropertySet->GetProperty(pID, res);
+
+  return ok;
 }
 
 
 // Set property in global info property set
 Boolean PFileFlashPixView::SetGlobalInfoProperty (DWORD pID, DWORD propType, OLEProperty ** res)
 {
-  return globalInfoPropertySet->NewProperty(pID, propType, res);
+  Boolean ok = TRUE;
+
+  // If absent, there is an error
+  if (globalInfoPropertySet == NULL)
+    ok = FALSE;
+
+  // Get the property
+  if (ok)
+    ok = globalInfoPropertySet->NewProperty(pID, propType, res);
+
+  return ok;
 }
 
 
