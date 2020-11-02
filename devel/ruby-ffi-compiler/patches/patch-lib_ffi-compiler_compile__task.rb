$NetBSD: patch-lib_ffi-compiler_compile__task.rb,v 1.1 2020/11/02 15:13:27 taca Exp $

Do not use FFI::Compiler::Platform own definition and use
RbConfig::CONFIG['arch'] instead.

--- lib/ffi-compiler/compile_task.rb.orig	2020-11-02 14:39:47.900421091 +0000
+++ lib/ffi-compiler/compile_task.rb
@@ -95,7 +95,7 @@ module FFI
         end
         so_flags = so_flags.join(' ')
 
-        out_dir = "#{@platform.arch}-#{@platform.os}"
+        out_dir = RbConfig::CONFIG['arch']
         if @ext_dir != '.'
           out_dir = File.join(@ext_dir, out_dir)
         end
