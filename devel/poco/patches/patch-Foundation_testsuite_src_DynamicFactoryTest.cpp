$NetBSD: patch-Foundation_testsuite_src_DynamicFactoryTest.cpp,v 1.1 2012/11/16 00:43:36 joerg Exp $

--- Foundation/testsuite/src/DynamicFactoryTest.cpp.orig	2012-11-14 11:57:05.000000000 +0000
+++ Foundation/testsuite/src/DynamicFactoryTest.cpp
@@ -109,7 +109,7 @@ void DynamicFactoryTest::testDynamicFact
 	
 	try
 	{
-		std::auto_ptr<B> b(dynamic_cast<B*>(dynFactory.createInstance("B")));
+		std::auto_ptr<B> b2(dynamic_cast<B*>(dynFactory.createInstance("B")));
 		fail("unregistered - must throw");
 	}
 	catch (Poco::NotFoundException&)
