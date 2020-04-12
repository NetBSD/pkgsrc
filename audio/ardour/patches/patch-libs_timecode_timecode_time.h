$NetBSD: patch-libs_timecode_timecode_time.h,v 1.1 2020/04/12 19:36:26 joerg Exp $

Ensure operators are defined in the namespace of one of the arguments.

--- libs/timecode/timecode/time.h.orig	2020-04-11 23:54:59.821584371 +0000
+++ libs/timecode/timecode/time.h
@@ -140,9 +140,8 @@ void LIBTIMECODE_API sample_to_timecode 
 		bool offset_is_negative, int64_t offset_samples
 		);
 
+extern LIBTIMECODE_API std::ostream& operator<< (std::ostream& ostr, const Time& t);
 
 } // namespace Timecode
 
-extern LIBTIMECODE_API std::ostream& operator<< (std::ostream& ostr, const Timecode::Time& t);
-
 #endif  // __timecode_time_h__
