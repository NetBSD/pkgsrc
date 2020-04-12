$NetBSD: patch-libs_pbd_id.cc,v 1.1 2020/04/12 19:36:26 joerg Exp $

Ensure operators are defined in the namespace of one of the arguments.

--- libs/pbd/id.cc.orig	2020-04-12 00:33:29.293934558 +0000
+++ libs/pbd/id.cc
@@ -102,10 +102,11 @@ ID::operator= (const ID& other)
 	return *this;
 }
 
+namespace PBD {
 ostream&
 operator<< (ostream& ostr, const ID& id)
 {
 	ostr << id.to_s();
 	return ostr;
 }
-
+}
