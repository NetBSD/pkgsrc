$NetBSD: patch-lib_xz_lib__lzma.rb,v 1.3 2015/03/01 12:58:17 taca Exp $

Use an absolute path for a library to load.

--- lib/xz/lib_lzma.rb.orig	2014-08-15 07:57:40.000000000 +0000
+++ lib/xz/lib_lzma.rb
@@ -71,7 +71,7 @@ module XZ
     :lzma_buf_error,
     :lzma_prog_error
 
-    ffi_lib ['lzma.so.5', 'lzma.so', 'lzma']
+    ffi_lib ['liblzma.@SHLIB_EXT@.5', 'liblzma.@SHLIB_EXT@', 'liblzma'].map! { |f|  File.join('@LOCALBASE@/lib', f) }
 
     attach_function :lzma_easy_encoder, [:pointer, :uint32, :int], :int, :blocking => true
     attach_function :lzma_code, [:pointer, :int], :int, :blocking => true
