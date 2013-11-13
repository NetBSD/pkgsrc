$NetBSD: patch-lib_xz_lib__lzma.rb,v 1.2 2013/11/13 18:10:20 minskim Exp $

Use an absolute path for a library to load.

--- lib/xz/lib_lzma.rb.orig	2012-03-19 09:42:58.000000000 +0000
+++ lib/xz/lib_lzma.rb
@@ -71,7 +71,7 @@ module XZ
     :lzma_buf_error,
     :lzma_prog_error
     
-    ffi_lib ['lzma.so.2', 'lzma.so', 'lzma']
+    ffi_lib ['liblzma.@SHLIB_EXT@.2', 'liblzma.@SHLIB_EXT@', 'liblzma'].map! { |f|  File.join('@LOCALBASE@/lib', f) }
     
     attach_function :lzma_easy_encoder, [:pointer, :uint32, :int], :int
     attach_function :lzma_code, [:pointer, :int], :int
