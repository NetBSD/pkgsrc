$NetBSD: patch-src_3rdparty_opennurbs_zlib_zconf.h,v 1.1 2025/08/19 12:52:17 plunky Exp $

as we are using private zlib, also apply prefix to other symbols to prevent
cross contamination with other users

--- src/3rdparty/opennurbs/zlib/zconf.h.orig	2025-08-17 10:19:40.640835518 +0000
+++ src/3rdparty/opennurbs/zlib/zconf.h
@@ -83,6 +83,18 @@ warning C4127: conditional expression is
 #  define get_crc_table         z_get_crc_table
 #  define zError                z_zError
 
+#  define adler32_combine       z_adler32_combine
+#  define crc32_combine         z_crc32_combine
+#  define deflateSetHeader      z_deflateSetHeader
+#  define deflateTune           z_deflateTune
+#  define inflateBackInit_      z_inflateBackInit_
+#  define inflate_fast          z_inflate_fast
+#  define inflateGetHeader      z_inflateGetHeader
+#  define inflatePrime          z_inflatePrime
+#  define inflate_table         z_inflate_table
+#  define zlibCompileFlags      z_zlibCompileFlags
+#  define zlibVersion           z_zlibVersion
+
 #  define alloc_func            z_alloc_func
 #  define free_func             z_free_func
 #  define in_func               z_in_func
