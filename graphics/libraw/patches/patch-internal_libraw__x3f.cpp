$NetBSD: patch-internal_libraw__x3f.cpp,v 1.1 2015/10/05 04:37:39 richard Exp $

undefine DS if sys/regset.h is pulled in on SunOS

--- internal/libraw_x3f.cpp.orig	2015-05-16 12:32:15.000000000 +0000
+++ internal/libraw_x3f.cpp
@@ -619,7 +619,9 @@ static x3f_huffman_t *new_huffman(x3f_hu
 /* --------------------------------------------------------------------- */
 /* Creating a new x3f structure from file                                */
 /* --------------------------------------------------------------------- */
-
+#ifdef DS
+#undef DS
+#endif
 /* extern */ x3f_t *x3f_new_from_file(LibRaw_abstract_datastream *infile)
 {
   x3f_t *x3f = (x3f_t *)calloc(1, sizeof(x3f_t));
