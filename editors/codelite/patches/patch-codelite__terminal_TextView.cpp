$NetBSD: patch-codelite__terminal_TextView.cpp,v 1.3 2019/08/27 14:45:04 wiz Exp $

Compilation fix for wx3.0 gtk+3 builds.

--- codelite_terminal/TextView.cpp.orig   2019-05-21 17:52:21.000000000 +0300
+++ codelite_terminal/TextView.cpp
@@ -12,7 +12,11 @@
     m_ctrl->SetCaretStyle(wxSTC_CARETSTYLE_BLOCK);
     m_ctrl->SetYCaretPolicy(wxSTC_CARET_STRICT | wxSTC_CARET_SLOP, 4);
     m_ctrl->SetLexer(wxSTC_LEX_CONTAINER);
+#if wxCHECK_VERSION(3, 1, 1)
     m_ctrl->StartStyling(0);
+#else
+    m_ctrl->StartStyling(0, 0x1f);
+#endif
     m_ctrl->SetWrapMode(wxSTC_WRAP_CHAR);
 #else
     m_ctrl = new TextCtrl_t(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize,
@@ -61,7 +65,11 @@
 {
 #if USE_STC
     m_defaultAttr = attr;
+#if wxCHECK_VERSION(3, 1, 1)
     m_ctrl->StartStyling(m_ctrl->GetLastPosition());
+#else
+    m_ctrl->StartStyling(m_ctrl->GetLastPosition(), 0x1f);
+#endif
 #else
     m_ctrl->SetDefaultStyle(attr);
 #endif
@@ -210,6 +218,10 @@
 #if USE_STC
     m_ctrl->ClearAll();
     m_ctrl->ClearDocumentStyle();
+#if wxCHECK_VERSION(3, 1, 1)
     m_ctrl->StartStyling(0);
-#endif
-}
+#else
+    m_ctrl->StartStyling(0, 0x1f);
+#endif
+#endif
+}
