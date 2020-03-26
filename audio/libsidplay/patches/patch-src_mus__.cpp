$NetBSD: patch-src_mus__.cpp,v 1.1 2020/03/26 21:32:37 rillig Exp $

mus_.cpp: In member function 'virtual bool sidTune::MUS_fileSupport(const void*, udword)':
mus_.cpp:76:38: error: array subscript has type 'char' [-Werror=char-subscripts]
                 infoString[line][si++] = c;  // copy to info string
                                      ^

Using a char here is ok, but GCC cannot prove it. It is used only in the
range [0, 31].

--- src/mus_.cpp.orig	2004-08-17 11:43:38.000000000 +0000
+++ src/mus_.cpp
@@ -66,7 +66,7 @@ bool sidTune::MUS_fileSupport(const void
     for ( int line = 0; line < 5; line++ )
     {
         char c;
-        char si = 0;  // count copied characters
+        unsigned char si = 0;  // count copied characters
         do
         {
             // ASCII CHR$ conversion
