$NetBSD: patch-internal_libraw__x3f.cpp,v 1.2 2018/04/14 03:45:56 markd Exp $

undefine DS if sys/regset.h is pulled in on SunOS

--- internal/libraw_x3f.cpp.orig	2018-02-24 09:47:43.000000000 +0000
+++ internal/libraw_x3f.cpp
@@ -710,6 +710,9 @@ static x3f_huffman_t *new_huffman(x3f_hu
 /* --------------------------------------------------------------------- */
 /* Creating a new x3f structure from file                                */
 /* --------------------------------------------------------------------- */
+#ifdef DS
+#undef DS
+#endif
 
 /* extern */ x3f_t *x3f_new_from_file(LibRaw_abstract_datastream *infile)
 {
