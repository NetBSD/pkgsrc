$NetBSD: patch-src_fstream__unicode.h,v 1.1 2014/01/02 15:52:56 wiz Exp $

clang support from upstream SVN 278.

--- src/fstream_unicode.h.orig	2009-09-15 04:49:36.000000000 +0000
+++ src/fstream_unicode.h
@@ -57,7 +57,7 @@ std::string, without the need of calling
 
 */
 
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__llvm__)
 
 #include  <ext/stdio_filebuf.h>
 #include  <istream>
@@ -578,7 +578,7 @@ typedef basic_ofstream_unicode<char> ofs
 typedef basic_fstream_unicode<char> fstream_unicode;
 
 
-#elif defined(_MSC_VER) && _MSC_VER>=1400 // #ifdef __GNUC__
+#elif defined(_MSC_VER) && _MSC_VER>=1400 // #if defined(__GNUC__) && !defined(__llvm__)
 
 // Visual Studio port by Sebastian Schuberth
 
@@ -682,7 +682,17 @@ class fstream_utf8:public std::fstream
     }
 };
 
-#else // _MSC_VER / __GNUC__
+#elif defined(__llvm__)
+
+    #include  <fstream>
+
+    //ttt2 not sure these are enough outside Linux
+    typedef std::basic_ifstream<char> ifstream_utf8;
+    typedef std::basic_ofstream<char> ofstream_utf8;
+    typedef std::basic_fstream<char> fstream_utf8;
+
+
+#else // _MSC_VER / gcc / __llvm__
 
     //#error classes i/ofstream_utf8 need to be ported to this compiler
     #warning classes i/ofstream_utf8 need to be ported to your compiler
@@ -693,6 +703,6 @@ class fstream_utf8:public std::fstream
     typedef std::basic_ofstream<char> ofstream_utf8;
     typedef std::basic_fstream<char> fstream_utf8;
 
-#endif // _MSC_VER / __GNUC__
+#endif // _MSC_VER / gcc / __llvm__
 
 #endif // FStreamUtf8H
