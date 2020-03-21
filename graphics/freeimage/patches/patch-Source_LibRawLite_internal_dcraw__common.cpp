$NetBSD: patch-Source_LibRawLite_internal_dcraw__common.cpp,v 1.1 2020/03/21 16:41:41 rillig Exp $

Source/LibRawLite/internal/dcraw_common.cpp: In member function 'void LibRaw::xtrans_interpolate(int)':
Source/LibRawLite/internal/dcraw_common.cpp:5879:27: error: array subscript has type 'char' [-Werror=char-subscripts]
       cstat[fcol(row, col)]++;
                           ^

The expected values for fcol must be in the range 0..3 anyway, otherwise
the behavior is undefined. Instead of using char, it would probably be
better to use uint8_t here.

https://sourceforge.net/p/freeimage/bugs/322/

--- Source/LibRawLite/internal/dcraw_common.cpp.orig	2018-06-30 02:08:06.000000000 +0000
+++ Source/LibRawLite/internal/dcraw_common.cpp
@@ -5876,7 +5876,7 @@ void CLASS xtrans_interpolate(int passes
                                        /* Check against right pattern */
   for (row = 0; row < 6; row++)
     for (col = 0; col < 6; col++)
-      cstat[fcol(row, col)]++;
+      cstat[(unsigned char)fcol(row, col)]++;
 
   if (cstat[0] < 6 || cstat[0] > 10 || cstat[1] < 16 || cstat[1] > 24 || cstat[2] < 6 || cstat[2] > 10 || cstat[3])
     throw LIBRAW_EXCEPTION_IO_CORRUPT;
