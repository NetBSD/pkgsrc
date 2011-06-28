$NetBSD: patch-include_cppunit_Message.h,v 1.1 2011/06/28 09:28:24 wiz Exp $

devel/cppunit misses a destructor declaration for one of its classes.
The compiler generates an implicit destructor but in certain circonstances this leads to crashes.
More information is available in this bug report on Red Hat's tracker:
https://bugzilla.redhat.com/show_bug.cgi?id=641350

--- include/cppunit/Message.h.orig	2004-11-19 20:00:44.000000000 +0000
+++ include/cppunit/Message.h
@@ -57,6 +57,8 @@ public:
            const std::string &detail2,
            const std::string &detail3 );
 
+  ~Message();
+
   Message &operator =( const Message &other );
 
   /*! \brief Returns the short description.
