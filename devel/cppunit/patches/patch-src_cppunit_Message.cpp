$NetBSD: patch-src_cppunit_Message.cpp,v 1.1 2011/06/28 09:28:24 wiz Exp $

devel/cppunit misses a destructor declaration for one of its classes.
The compiler generates an implicit destructor but in certain circonstances this leads to crashes.
More information is available in this bug report on Red Hat's tracker:
https://bugzilla.redhat.com/show_bug.cgi?id=641350

--- src/cppunit/Message.cpp.orig	2004-11-19 20:00:44.000000000 +0000
+++ src/cppunit/Message.cpp
@@ -47,6 +47,10 @@ Message::Message( const std::string &sho
   addDetail( detail1, detail2, detail3 );
 }
 
+Message::~Message()
+{
+}
+
 Message &
 Message::operator =( const Message &other )
 {
