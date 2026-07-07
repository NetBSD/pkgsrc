$NetBSD: patch-src_base_string.cc,v 1.1 2026/07/07 09:17:27 prlw1 Exp $

Avoid 226 being interpreted as -30 when running the tutorial.

--- src/base/string.cc.orig	2026-02-17 15:34:33.000000000 +0000
+++ src/base/string.cc
@@ -23,7 +23,7 @@ std::string to_lower(const std::string& str) {
 std::string to_lower(const std::string& str) {
 	std::string s;
 	for (const char* c = str.c_str(); *c != 0; ++c) {
-		s.push_back(tolower(*c));
+		s.push_back(tolower(static_cast<unsigned char>(*c)));
 	}
 	return s;
 }
@@ -32,7 +32,7 @@ bool iequals(const std::string& str1, const std::strin
 	const char* a = str1.c_str();
 	const char* b = str2.c_str();
 	for (; (*a != 0) && (*b != 0); ++a, ++b) {
-		if (tolower(*a) != tolower(*b)) {
+		if (tolower(static_cast<unsigned char>(*a)) != tolower(static_cast<unsigned char>(*b))) {
 			return false;
 		}
 	}
@@ -43,7 +43,7 @@ bool starts_with(const std::string& str, const std::st
 	const char* a = str.c_str();
 	const char* b = test.c_str();
 	for (; (*a != 0) && (*b != 0); ++a, ++b) {
-		if (case_sensitive ? (*a != *b) : (tolower(*a) != tolower(*b))) {
+		if (case_sensitive ? (*a != *b) : (tolower(static_cast<unsigned char>(*a)) != tolower(static_cast<unsigned char>(*b)))) {
 			return false;
 		}
 	}
@@ -71,7 +71,7 @@ bool ends_with(const std::string& str, const std::stri
 	for (; len_b != 0u; --len_b) {
 		--b;
 		--a;
-		if (case_sensitive ? (*a != *b) : (tolower(*a) != tolower(*b))) {
+		if (case_sensitive ? (*a != *b) : (tolower(static_cast<unsigned char>(*a)) != tolower(static_cast<unsigned char>(*b)))) {
 			return false;
 		}
 	}
