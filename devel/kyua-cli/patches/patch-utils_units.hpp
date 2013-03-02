$NetBSD: patch-utils_units.hpp,v 1.1 2013/03/02 18:16:39 joerg Exp $

--- utils/units.hpp.orig	2013-02-28 22:00:54.000000000 +0000
+++ utils/units.hpp
@@ -83,11 +83,11 @@ public:
     operator uint64_t(void) const;
 };
 
+std::istream& operator>>(std::istream&, bytes&);
+std::ostream& operator<<(std::ostream&, const bytes&);
 
 }  // namespace units
 }  // namespace utils
 
-std::istream& operator>>(std::istream&, utils::units::bytes&);
-std::ostream& operator<<(std::ostream&, const utils::units::bytes&);
 
 #endif  // !defined(UTILS_UNITS_HPP)
