$NetBSD: patch-lib_ffi-compiler_compile__task.rb,v 1.2 2024/03/24 14:04:18 taca Exp $

Do not use FFI::Compiler::Platform own definition and use
RbConfig::CONFIG['arch'] instead.

--- lib/ffi-compiler/compile_task.rb.orig	2024-03-23 12:59:05.934181248 +0000
+++ lib/ffi-compiler/compile_task.rb
@@ -122,7 +122,7 @@ module FFI
         end
         so_flags = shelljoin(so_flags)
 
-        out_dir = "#{@platform.arch}-#{@platform.os}"
+        out_dir = RbConfig::CONFIG['arch']
         if @ext_dir != '.'
           out_dir = File.join(@ext_dir, out_dir)
         end
