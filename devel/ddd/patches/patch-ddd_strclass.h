$NetBSD: patch-ddd_strclass.h,v 1.1 2013/08/27 15:43:19 joerg Exp $

--- ddd/strclass.h.orig	2013-08-27 14:42:50.000000000 +0000
+++ ddd/strclass.h
@@ -543,7 +543,6 @@ public:
     bool OK() const; 
 };
 
-
 class string
 {
     friend class subString;
@@ -811,9 +810,9 @@ public:
 		     const regex& sep);
 
     friend string common_prefix(const string& x, const string& y, 
-				int startpos = 0);
+				int startpos);
     friend string common_suffix(const string& x, const string& y, 
-				int startpos = -1);
+				int startpos);
     friend string replicate(char c, int n);
     friend string replicate(const string& y, int n);
     friend string join(const string *src, int n, const string& sep);
@@ -864,8 +863,8 @@ public:
     friend std::istream& operator>>(std::istream& s, string& x);
 
     friend int readline(std::istream& s, string& x, 
-			char terminator = '\n',
-			int discard_terminator = 1);
+			char terminator,
+			int discard_terminator);
 
     // Status
     unsigned int length() const;
@@ -882,6 +881,14 @@ public:
     bool OK() const;
 };
 
+string common_prefix(const string& x, const string& y,
+				int startpos = 0);
+string common_suffix(const string& x, const string& y,
+				int startpos = -1);
+int readline(std::istream& s, string& x,
+			char terminator = '\n',
+			int discard_terminator = 1);
+
 // Inject names manually to accomodate argument-dependent name lookup (ADL)
 // (aka Koenig lookup). The rule is that friend declarations are visible
 // when found through ADL because an argument of the call happens to be
