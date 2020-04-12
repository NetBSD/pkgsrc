$NetBSD: patch-libs_ardour_ardour_chan__count.h,v 1.1 2020/04/12 19:36:26 joerg Exp $

Ensure operators are defined in the namespace of one of the arguments.

--- libs/ardour/ardour/chan_count.h.orig	2020-04-11 23:20:16.360459913 +0000
+++ libs/ardour/ardour/chan_count.h
@@ -207,9 +207,9 @@ private:
 	uint32_t _counts[DataType::num_types];
 };
 
-} // namespace ARDOUR
+LIBARDOUR_API std::ostream& operator<<(std::ostream& o, const ChanCount& c);
 
-LIBARDOUR_API std::ostream& operator<<(std::ostream& o, const ARDOUR::ChanCount& c);
+} // namespace ARDOUR
 
 #endif // __ardour_chan_count_h__
 
