$NetBSD: patch-libs_timecode_src_time.cc,v 1.1 2020/04/12 19:36:26 joerg Exp $

Ensure operators are defined in the namespace of one of the arguments.

--- libs/timecode/src/time.cc.orig	2020-04-12 00:30:24.372761546 +0000
+++ libs/timecode/src/time.cc
@@ -844,10 +844,10 @@ sample_to_timecode (
 	timecode.drop = timecode_drop_frames;
 }
 
-} // namespace Timecode
-
 std::ostream&
 operator<<(std::ostream& ostr, const Timecode::Time& t)
 {
 	return t.print (ostr);
 }
+
+} // namespace Timecode
