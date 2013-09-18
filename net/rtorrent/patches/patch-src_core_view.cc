$NetBSD: patch-src_core_view.cc,v 1.3 2013/09/18 16:33:08 joerg Exp $

--- src/core/view.cc.orig	2012-02-14 03:32:01.000000000 +0000
+++ src/core/view.cc
@@ -172,7 +172,7 @@ View::initialize(const std::string& name
   m_focus = 0;
 
   set_last_changed(rak::timer());
-  m_delayChanged.slot() = std::tr1::bind(&signal_type::operator(), &m_signalChanged);
+  m_delayChanged.slot() = bind(&signal_type::operator(), &m_signalChanged);
 }
 
 void
