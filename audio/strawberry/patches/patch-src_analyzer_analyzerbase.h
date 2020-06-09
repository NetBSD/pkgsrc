$NetBSD: patch-src_analyzer_analyzerbase.h,v 1.1 2020/06/09 17:49:24 nia Exp $

analyzerbase.cpp:(.text+0x14): undefined reference to `vtable for Analyzer::Base'

XXX: Someone who understands C++ more should look at this...

--- src/analyzer/analyzerbase.h.orig	2020-04-07 14:46:17.199829715 +0000
+++ src/analyzer/analyzerbase.h
@@ -55,7 +55,7 @@ class Base : public QWidget {
   Q_OBJECT
 
  public:
-  ~Base() { delete fht_; }
+  ~Base();
 
   uint timeout() const { return timeout_; }
 
