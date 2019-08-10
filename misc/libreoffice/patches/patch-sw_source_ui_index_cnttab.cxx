$NetBSD: patch-sw_source_ui_index_cnttab.cxx,v 1.1 2019/08/10 11:41:29 ryoon Exp $

--- sw/source/ui/index/cnttab.cxx.orig	2019-08-06 17:26:35.000000000 +0000
+++ sw/source/ui/index/cnttab.cxx
@@ -1554,7 +1554,7 @@ void SwTOXEdit::AdjustSize()
 {
     auto nWidth = m_xEntry->get_pixel_size(GetText()).Width();
     float fChars = nWidth / m_xEntry->get_approximate_digit_width();
-    m_xEntry->set_width_chars(std::max(1.0f, ceil(fChars)));
+    m_xEntry->set_width_chars(std::max((double)1.0f, (double)ceil(fChars)));
 }
 
 class SwTOXButton : public SwTOXWidget
