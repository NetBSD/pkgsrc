$NetBSD: patch-tests_string.cpp,v 1.1 2016/07/21 17:16:17 wiz Exp $

SVN 7667

--- tests/string.cpp.orig	2016-01-31 10:35:01.000000000 +0000
+++ tests/string.cpp
@@ -11,6 +11,7 @@ class string_test : public CppUnit::Test
 	CPPUNIT_TEST_SUITE(string_test);
 	CPPUNIT_TEST(test_conversion);
 	CPPUNIT_TEST(test_conversion2);
+	CPPUNIT_TEST(test_conversion_utf8);
 	CPPUNIT_TEST_SUITE_END();
 
 public:
@@ -19,6 +20,7 @@ public:
 
 	void test_conversion();
 	void test_conversion2();
+	void test_conversion_utf8();
 };
 
 CPPUNIT_TEST_SUITE_REGISTRATION(string_test);
@@ -43,7 +45,7 @@ void string_test::test_conversion()
 
 void string_test::test_conversion2()
 {
-	wchar_t p[] = { 'M', 'o', 't', 0xf6, 'r', 'h', 'e', 'a', 'd', 0 };
+	wchar_t const p[] = { 'M', 'o', 't', 0xf6, 'r', 'h', 'e', 'a', 'd', 0 };
 	std::wstring const w(p);
 
 	std::string const s = fz::to_string(w);
@@ -54,3 +56,22 @@ void string_test::test_conversion2()
 
 	ASSERT_EQUAL(w, w2);
 }
+
+void string_test::test_conversion_utf8()
+{
+	wchar_t const p[] = { 'M', 'o', 't', 0xf6, 'r', 'h', 'e', 'a', 'd', 0 };
+	unsigned char const p_utf8[] = { 'M', 'o', 't', 0xc3, 0xb6, 'r', 'h', 'e', 'a', 'd', 0 };
+
+	std::wstring const w(p);
+	std::string const u(reinterpret_cast<char const*>(p_utf8));
+
+	std::string const s = fz::to_utf8(w);
+
+	CPPUNIT_ASSERT(s.size() >= w.size());
+
+	ASSERT_EQUAL(s, u);
+
+	std::wstring const w2 = fz::to_wstring_from_utf8(s);
+
+	ASSERT_EQUAL(w, w2);
+}
