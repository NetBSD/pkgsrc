$NetBSD: patch-src_irc_inputfilter.cpp,v 1.1 2020/05/26 11:27:01 joerg Exp $

--- src/irc/inputfilter.cpp.orig	2020-05-25 23:58:34.377765792 +0000
+++ src/irc/inputfilter.cpp
@@ -2335,7 +2335,7 @@ int InputFilter::getAutomaticRequest(con
 
 void InputFilter::addWhoRequest(const QString& name) { m_whoRequestList << name.toLower(); }
 
-bool InputFilter::isWhoRequestUnderProcess(const QString& name) { return (m_whoRequestList.contains(name.toLower())>0); }
+bool InputFilter::isWhoRequestUnderProcess(const QString& name) { return (m_whoRequestList.contains(name.toLower())); }
 
 void InputFilter::setLagMeasuring(bool state) { m_lagMeasuring=state; }
 
