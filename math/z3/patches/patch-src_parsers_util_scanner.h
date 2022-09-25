$NetBSD: patch-src_parsers_util_scanner.h,v 1.1 2022/09/25 11:01:34 he Exp $

Adapt to systems where char == unsigned char.

--- src/parsers/util/scanner.h.orig	2018-11-19 20:21:17.000000000 +0000
+++ src/parsers/util/scanner.h
@@ -63,7 +63,7 @@ private:
     rational           m_number;
     unsigned           m_bv_size;
     token              m_state;
-    char               m_normalized[256];
+    signed char        m_normalized[256];
     vector<char>       m_string;
     std::istream&      m_stream;
     std::ostream&      m_err;
@@ -76,8 +76,8 @@ private:
     bool               m_smt2;
     bool               m_bv_token;
 
-    char read_char();
-    token read_symbol(char ch);
+    signed char read_char();
+    token read_symbol(signed char ch);
     void unread_char();
     void comment(char delimiter);
     token read_id(char first_char);
