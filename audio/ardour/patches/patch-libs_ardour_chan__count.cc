$NetBSD: patch-libs_ardour_chan__count.cc,v 1.1 2020/04/12 19:36:26 joerg Exp $

Ensure operators are defined in the namespace of one of the arguments.

--- libs/ardour/chan_count.cc.orig	2020-04-12 00:31:30.948259759 +0000
+++ libs/ardour/chan_count.cc
@@ -67,8 +67,8 @@ ChanCount::state(const std::string& name
 // Statics
 const ChanCount ChanCount::ZERO     = ChanCount();
 
-} // namespace ARDOUR
-
 std::ostream& operator<<(std::ostream& o, const ARDOUR::ChanCount& c) {
 	return o << "AUDIO=" << c.n_audio() << ":MIDI=" << c.n_midi();
 }
+
+} // namespace ARDOUR
