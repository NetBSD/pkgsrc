$NetBSD: patch-libs_ardour_ardour_chan__mapping.h,v 1.1 2020/04/12 19:36:26 joerg Exp $

Ensure operators are defined in the namespace of one of the arguments.

--- libs/ardour/ardour/chan_mapping.h.orig	2020-04-11 23:30:11.328024715 +0000
+++ libs/ardour/ardour/chan_mapping.h
@@ -118,9 +118,9 @@ private:
 	Mappings _mappings;
 };
 
-} // namespace ARDOUR
+std::ostream& operator<<(std::ostream& o, const ChanMapping& m);
 
-std::ostream& operator<<(std::ostream& o, const ARDOUR::ChanMapping& m);
+} // namespace ARDOUR
 
 #endif // __ardour_chan_mapping_h__
 
