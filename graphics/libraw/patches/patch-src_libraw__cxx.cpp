$NetBSD: patch-src_libraw__cxx.cpp,v 1.1 2015/10/05 04:37:39 richard Exp $
  
undefine DS if sys/regset.h is pulled in on SunOS                               

--- src/libraw_cxx.cpp.orig	2015-05-16 12:32:15.000000000 +0000
+++ src/libraw_cxx.cpp
@@ -3623,6 +3623,9 @@ void LibRaw::parse_x3f()
   _x3f_data = x3f;
 
   x3f_header_t *H = NULL;
+#ifdef DS
+#undef DS
+#endif
   x3f_directory_section_t *DS = NULL;
 
   H = &x3f->header;
