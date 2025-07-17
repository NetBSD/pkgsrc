$NetBSD: patch-ext_win32_resolv_resolv.c,v 1.1.2.2 2025/07/17 02:45:43 maya Exp $

Update resolv gem to 0.6.2.

--- ext/win32/resolv/resolv.c.orig	2025-05-14 03:11:06.000000000 +0000
+++ ext/win32/resolv/resolv.c
@@ -13,6 +13,8 @@ w32error_make_error(DWORD e)
     return rb_class_new_instance(1, &code, rb_path2class("Win32::Resolv::Error"));
 }
 
+NORETURN(static void w32error_raise(DWORD e));
+
 static void
 w32error_raise(DWORD e)
 {
