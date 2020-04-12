$NetBSD: patch-libs_ardour_ardour_presentation__info.h,v 1.1 2020/04/12 19:36:26 joerg Exp $

Ensure operators are defined in the namespace of one of the arguments.

--- libs/ardour/ardour/presentation_info.h.orig	2020-04-11 23:14:40.532791103 +0000
+++ libs/ardour/ardour/presentation_info.h
@@ -267,8 +267,8 @@ class LIBARDOUR_API PresentationInfo : p
 	static int selection_counter;
 };
 
-}
+std::ostream& operator<<(std::ostream& o, PresentationInfo const& rid);
 
-std::ostream& operator<<(std::ostream& o, ARDOUR::PresentationInfo const& rid);
+}
 
 #endif /* __libardour_presentation_info_h__ */
