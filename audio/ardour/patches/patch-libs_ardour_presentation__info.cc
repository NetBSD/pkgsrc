$NetBSD: patch-libs_ardour_presentation__info.cc,v 1.1 2020/04/12 19:36:26 joerg Exp $

Ensure operators are defined in the namespace of one of the arguments.

--- libs/ardour/presentation_info.cc.orig	2020-04-12 00:31:00.855675925 +0000
+++ libs/ardour/presentation_info.cc
@@ -282,8 +282,10 @@ PresentationInfo::operator= (Presentatio
 	return *this;
 }
 
+namespace ARDOUR {
 std::ostream&
 operator<<(std::ostream& o, ARDOUR::PresentationInfo const& pi)
 {
 	return o << pi.order() << '/' << enum_2_string (pi.flags()) << '/' << pi.color();
 }
+}
