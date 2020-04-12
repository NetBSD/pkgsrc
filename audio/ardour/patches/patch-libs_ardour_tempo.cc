$NetBSD: patch-libs_ardour_tempo.cc,v 1.1 2020/04/12 19:36:26 joerg Exp $

Ensure operators are defined in the namespace of one of the arguments.

--- libs/ardour/tempo.cc.orig	2020-04-12 00:13:33.975439051 +0000
+++ libs/ardour/tempo.cc
@@ -4872,6 +4872,7 @@ struct bbtcmp {
     }
 };
 
+namespace ARDOUR {
 std::ostream&
 operator<< (std::ostream& o, const Meter& m) {
 	return o << m.divisions_per_bar() << '/' << m.note_divisor();
@@ -4898,3 +4899,4 @@ operator<< (std::ostream& o, const Metri
 
 	return o;
 }
+}
