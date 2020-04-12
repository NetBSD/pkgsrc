$NetBSD: patch-libs_timecode_timecode_bbt__time.h,v 1.1 2020/04/12 19:36:26 joerg Exp $

Ensure operators are defined in the namespace of one of the arguments.

--- libs/timecode/timecode/bbt_time.h.orig	2020-04-12 00:17:52.012246383 +0000
+++ libs/timecode/timecode/bbt_time.h
@@ -76,17 +76,15 @@ struct LIBTIMECODE_API BBT_Time {
 	}
 };
 
-}
-
 inline std::ostream&
-operator<< (std::ostream& o, const Timecode::BBT_Time& bbt)
+operator<< (std::ostream& o, const BBT_Time& bbt)
 {
 	o << bbt.bars << '|' << bbt.beats << '|' << bbt.ticks;
 	return o;
 }
 
 inline std::ostream&
-print_padded (std::ostream& o, const Timecode::BBT_Time& bbt)
+print_padded (std::ostream& o, const BBT_Time& bbt)
 {
 	o << std::setfill ('0') << std::right
 	  << std::setw (3) << bbt.bars << "|"
@@ -96,4 +94,6 @@ print_padded (std::ostream& o, const Tim
 	return o;
 }
 
+}
+
 #endif /* __timecode_bbt_time_h__ */
