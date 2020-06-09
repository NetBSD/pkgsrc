$NetBSD: patch-src_analyzer_analyzerbase.cpp,v 1.1 2020/06/09 17:49:24 nia Exp $

analyzerbase.cpp:(.text+0x14): undefined reference to `vtable for Analyzer::Base'

XXX: Someone who understands C++ more should look at this...

--- src/analyzer/analyzerbase.cpp.orig	2020-04-07 14:46:17.199829715 +0000
+++ src/analyzer/analyzerbase.cpp
@@ -65,6 +65,8 @@ Analyzer::Base::Base(QWidget *parent, ui
       new_frame_(false),
       is_playing_(false) {}
 
+Analyzer::Base::~Base() { delete fht_; }
+
 void Analyzer::Base::hideEvent(QHideEvent*) { timer_.stop(); }
 
 void Analyzer::Base::showEvent(QShowEvent*) { timer_.start(timeout(), this); }
