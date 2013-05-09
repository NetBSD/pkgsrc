$NetBSD: patch-src_core_view.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/core/view.cc.orig	2013-05-03 22:47:53.000000000 +0000
+++ src/core/view.cc
@@ -172,7 +172,7 @@ View::initialize(const std::string& name
   m_focus = 0;
 
   set_last_changed(rak::timer());
-  m_delayChanged.slot() = std::tr1::bind(&signal_type::operator(), &m_signalChanged);
+  m_delayChanged.slot() = bind(&signal_type::operator(), &m_signalChanged);
 }
 
 void
