$NetBSD: patch-Swiften_Serializer_StreamResumedSerializer.cpp,v 1.1 2014/09/19 07:05:24 wiz Exp $

Fix build with boost-1.56.0. From upstream git.

--- Swiften/Serializer/StreamResumedSerializer.cpp.orig	2012-12-22 12:23:59.000000000 +0000
+++ Swiften/Serializer/StreamResumedSerializer.cpp
@@ -22,7 +22,7 @@ SafeByteArray StreamResumedSerializer::s
 	XMLElement element("resumed", "urn:xmpp:sm:2");
 	element.setAttribute("previd", e->getResumeID());
 	if (e->getHandledStanzasCount()) {
-		element.setAttribute("h", boost::lexical_cast<std::string>(e->getHandledStanzasCount()));
+		element.setAttribute("h", boost::lexical_cast<std::string>(e->getHandledStanzasCount().get()));
 	}
 	return createSafeByteArray(element.serialize());
 }
