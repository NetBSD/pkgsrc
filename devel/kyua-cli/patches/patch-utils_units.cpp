$NetBSD: patch-utils_units.cpp,v 1.1 2013/03/02 18:16:39 joerg Exp $

--- utils/units.cpp.orig	2013-02-28 22:07:12.000000000 +0000
+++ utils/units.cpp
@@ -143,7 +143,7 @@ units::bytes::operator uint64_t(void) co
 ///
 /// \post The bad bit of input is set to 1 if the parsing failed.
 std::istream&
-operator>>(std::istream& input, units::bytes& rhs)
+units::operator>>(std::istream& input, units::bytes& rhs)
 {
     std::string word;
     input >> word;
@@ -166,7 +166,7 @@ operator>>(std::istream& input, units::b
 ///
 /// \return The output stream.
 std::ostream&
-operator<<(std::ostream& output, const units::bytes& rhs)
+units::operator<<(std::ostream& output, const units::bytes& rhs)
 {
     return (output << rhs.format());
 }
