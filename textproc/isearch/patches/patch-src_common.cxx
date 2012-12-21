$NetBSD: patch-src_common.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use "std" qualification

--- src/common.cxx~	2000-09-06 21:14:26.000000000 +0000
+++ src/common.cxx
@@ -68,12 +68,12 @@ void
 panic(const char *filename, long line)
 #endif
 {
-  cerr << endl << "?Panic in line " << line
+  std::cerr << std::endl << "?Panic in line " << line
        << " of file " << filename
 #ifdef HAS__FUNC__
        << "[" << func << "()]"
 #endif
-       << endl;
+       << std::endl;
   (void)perror("Unexpected error condition");
   abort();
 }
