$NetBSD: patch-libs_ardour_chan__mapping.cc,v 1.1 2020/04/12 19:36:26 joerg Exp $

Ensure operators are defined in the namespace of one of the arguments.

--- libs/ardour/chan_mapping.cc.orig	2020-04-12 00:31:19.718822358 +0000
+++ libs/ardour/chan_mapping.cc
@@ -241,10 +241,6 @@ ChanMapping::count () const
 	return rv;
 }
 
-
-
-} // namespace ARDOUR
-
 std::ostream& operator<<(std::ostream& o, const ARDOUR::ChanMapping& cm)
 {
 	const ARDOUR::ChanMapping::Mappings& mp (cm.mappings());
@@ -258,3 +254,5 @@ std::ostream& operator<<(std::ostream& o
 
 	return o;
 }
+
+} // namespace ARDOUR
