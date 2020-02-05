$NetBSD: patch-sw_source_ui_index_cnttab.cxx,v 1.2 2020/02/05 14:10:35 ryoon Exp $

--- sw/source/ui/index/cnttab.cxx.orig	2020-01-22 23:14:16.000000000 +0000
+++ sw/source/ui/index/cnttab.cxx
@@ -1545,7 +1545,7 @@ void SwTOXEdit::AdjustSize()
 {
     auto nWidth = m_xEntry->get_pixel_size(GetText()).Width();
     float fChars = nWidth / m_xEntry->get_approximate_digit_width();
-    m_xEntry->set_width_chars(std::max(1.0f, std::ceil(fChars)));
+    m_xEntry->set_width_chars(std::max((double)1.0f, (double)(std::ceil(fChars))));
 }
 
 class SwTOXButton : public SwTOXWidget
