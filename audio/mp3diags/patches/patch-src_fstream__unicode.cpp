$NetBSD: patch-src_fstream__unicode.cpp,v 1.1 2014/01/02 15:52:56 wiz Exp $

clang support from upstream SVN 278.

--- src/fstream_unicode.cpp.orig	2009-11-03 12:20:00.000000000 +0000
+++ src/fstream_unicode.cpp
@@ -19,7 +19,7 @@
  *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
  ***************************************************************************/
 
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__llvm__)
 
 
 #include  "fstream_unicode.h"
@@ -178,9 +178,10 @@ int unicodeOpenHlp(const int& fd, std::i
 
 //ttt2 review O_SHORT_LIVED
 
-#else // #ifdef __GNUC__
+#else // #if defined(__GNUC__) && !defined(__llvm__)
 
 // nothing to do for now; the MSVC version is fully inline and no ports to other compilers exist
 
-#endif // #ifdef __GNUC__
+#endif // #if defined(__GNUC__) && !defined(__llvm__)
+
 
