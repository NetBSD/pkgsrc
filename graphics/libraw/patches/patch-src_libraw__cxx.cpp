$NetBSD: patch-src_libraw__cxx.cpp,v 1.2 2021/09/19 18:46:50 nia Exp $

- Thumbnail size range check (CVE-2020-15503)
- undefine DS if sys/regset.h is pulled in on SunOS                               

--- src/libraw_cxx.cpp.orig	2019-08-20 17:34:30.000000000 +0000
+++ src/libraw_cxx.cpp
@@ -3712,6 +3712,20 @@ libraw_processed_image_t *LibRaw::dcraw_
     return NULL;
   }
 
+  if (T.tlength < 64u)
+  {
+      if (errcode)
+          *errcode = EINVAL;
+      return NULL;
+  }
+
+  if (INT64(T.tlength) > 1024ULL * 1024ULL * LIBRAW_MAX_THUMBNAIL_MB)
+  {
+      if (errcode)
+          *errcode = LIBRAW_TOO_BIG;
+      return NULL;
+  }
+
   if (T.tformat == LIBRAW_THUMBNAIL_BITMAP)
   {
     libraw_processed_image_t *ret = (libraw_processed_image_t *)::malloc(sizeof(libraw_processed_image_t) + T.tlength);
@@ -3976,6 +3990,12 @@ void LibRaw::kodak_thumb_loader()
   if (ID.toffset + est_datasize > ID.input->size() + THUMB_READ_BEYOND)
     throw LIBRAW_EXCEPTION_IO_EOF;
 
+  if(INT64(T.theight) * INT64(T.twidth) > 1024ULL * 1024ULL * LIBRAW_MAX_THUMBNAIL_MB)
+      throw LIBRAW_EXCEPTION_IO_CORRUPT;
+
+  if (INT64(T.theight) * INT64(T.twidth) < 64ULL)
+      throw LIBRAW_EXCEPTION_IO_CORRUPT;
+
   // some kodak cameras
   ushort s_height = S.height, s_width = S.width, s_iwidth = S.iwidth, s_iheight = S.iheight;
   ushort s_flags = libraw_internal_data.unpacker_data.load_flags;
@@ -4237,6 +4257,25 @@ int LibRaw::unpack_thumb(void)
   CHECK_ORDER_LOW(LIBRAW_PROGRESS_IDENTIFY);
   CHECK_ORDER_BIT(LIBRAW_PROGRESS_THUMB_LOAD);
 
+#define THUMB_SIZE_CHECKT(A) \
+  do { \
+    if (INT64(A) > 1024ULL * 1024ULL * LIBRAW_MAX_THUMBNAIL_MB) throw LIBRAW_EXCEPTION_IO_CORRUPT; \
+    if (INT64(A) > 0 &&  INT64(A) < 64ULL)        throw LIBRAW_EXCEPTION_IO_CORRUPT; \
+  } while (0)
+
+#define THUMB_SIZE_CHECKTNZ(A) \
+  do { \
+    if (INT64(A) > 1024ULL * 1024ULL * LIBRAW_MAX_THUMBNAIL_MB) throw LIBRAW_EXCEPTION_IO_CORRUPT; \
+    if (INT64(A) < 64ULL)        throw LIBRAW_EXCEPTION_IO_CORRUPT; \
+  } while (0)
+
+
+#define THUMB_SIZE_CHECKWH(W,H) \
+  do { \
+    if (INT64(W)*INT64(H) > 1024ULL * 1024ULL * LIBRAW_MAX_THUMBNAIL_MB) throw LIBRAW_EXCEPTION_IO_CORRUPT; \
+    if (INT64(W)*INT64(H) < 64ULL)        throw LIBRAW_EXCEPTION_IO_CORRUPT; \
+  } while (0)
+
   try
   {
     if (!libraw_internal_data.internal_data.input)
@@ -4267,6 +4306,7 @@ int LibRaw::unpack_thumb(void)
 
         if (INT64(ID.toffset) + tsize > ID.input->size() + THUMB_READ_BEYOND)
           throw LIBRAW_EXCEPTION_IO_EOF;
+        THUMB_SIZE_CHECKT(tsize);
       }
       else
       {
@@ -4280,6 +4320,8 @@ int LibRaw::unpack_thumb(void)
       ID.input->seek(ID.toffset, SEEK_SET);
       if (write_thumb == &LibRaw::jpeg_thumb)
       {
+        THUMB_SIZE_CHECKTNZ(T.tlength);
+
         if (T.thumb)
           free(T.thumb);
         T.thumb = (char *)malloc(T.tlength);
@@ -4326,6 +4368,7 @@ int LibRaw::unpack_thumb(void)
       {
         if (t_bytesps > 1)
           throw LIBRAW_EXCEPTION_IO_CORRUPT; // 8-bit thumb, but parsed for more bits
+	THUMB_SIZE_CHECKWH(T.twidth, T.theight);
         int t_length = T.twidth * T.theight * t_colors;
 
         if (T.tlength && T.tlength < t_length) // try to find tiff ifd with needed offset
@@ -4351,6 +4394,7 @@ int LibRaw::unpack_thumb(void)
                 T.tcolors = 1;
             }
             T.tlength = total_size;
+            THUMB_SIZE_CHECKTNZ(T.tlength);
             if (T.thumb)
               free(T.thumb);
             T.thumb = (char *)malloc(T.tlength);
@@ -4384,6 +4428,8 @@ int LibRaw::unpack_thumb(void)
         if (T.thumb)
           free(T.thumb);
 
+        THUMB_SIZE_CHECKTNZ(T.tlength);
+
         T.thumb = (char *)malloc(T.tlength);
         if (!T.tcolors)
           T.tcolors = t_colors;
@@ -4404,6 +4450,10 @@ int LibRaw::unpack_thumb(void)
         int i_length = T.twidth * T.theight * t_colors * 2;
         if (!T.tlength)
           T.tlength = o_length;
+        THUMB_SIZE_CHECKTNZ(o_length);
+        THUMB_SIZE_CHECKTNZ(i_length);
+        THUMB_SIZE_CHECKTNZ(T.tlength);
+
         ushort *t_thumb = (ushort *)calloc(i_length, 1);
         ID.input->read(t_thumb, 1, i_length);
         if ((libraw_internal_data.unpacker_data.order == 0x4949) == (ntohs(0x1234) == 0x1234))
@@ -6183,6 +6233,9 @@ void LibRaw::parse_x3f()
   _x3f_data = x3f;
 
   x3f_header_t *H = NULL;
+#ifdef DS
+#undef DS
+#endif
   x3f_directory_section_t *DS = NULL;
 
   H = &x3f->header;
