$NetBSD: patch-src_libfwbuilder_src_fwbuilder_AddressRange.cpp,v 1.1 2017/06/17 19:52:13 joerg Exp $

Adding integer to a char[] string doesn't do the right thing.

--- src/libfwbuilder/src/fwbuilder/AddressRange.cpp.orig	2017-06-10 17:41:07.168361613 +0000
+++ src/libfwbuilder/src/fwbuilder/AddressRange.cpp
@@ -79,7 +79,7 @@ FWObject& AddressRange::shallowDuplicate
     const AddressRange *n = dynamic_cast<const AddressRange *>(o);
     if (n==NULL)
         throw(FWException(
-"Attempt to copy incompatible object to AddressRange: objectID="+o->getId()));
+"Attempt to copy incompatible object to AddressRange: objectID="+std::to_string(o->getId())));
 
     start_address = n->getRangeStart();
     end_address   = n->getRangeEnd();
