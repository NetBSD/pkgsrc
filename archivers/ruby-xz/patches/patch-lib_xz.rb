$NetBSD: patch-lib_xz.rb,v 1.1.1.1 2011/10/03 19:51:05 minskim Exp $

Use an absolute path for a library to load.

--- lib/xz.rb.orig	2011-10-02 00:41:00.000000000 +0000
+++ lib/xz.rb
@@ -77,7 +77,7 @@ module XZ
                     :lzma_buf_error,
                     :lzma_prog_error
     
-    ffi_lib "liblzma"
+    ffi_lib "@LOCALBASE@/lib/liblzma.@SHLIB_EXT@"
     
     attach_function :lzma_easy_encoder, [:pointer, :uint32, :int], :int
     attach_function :lzma_code, [:pointer, :int], :int
