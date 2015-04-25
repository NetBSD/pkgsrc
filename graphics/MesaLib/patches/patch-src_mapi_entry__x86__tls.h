$NetBSD: patch-src_mapi_entry__x86__tls.h,v 1.1 2015/04/25 11:19:18 tnn Exp $

Fix --enable-glx-tls with clang. From FreeBSD.

--- src/mapi/entry_x86_tls.h.orig	2015-03-28 18:20:39.000000000 +0000
+++ src/mapi/entry_x86_tls.h
@@ -72,8 +72,8 @@ __asm__(".text");
 extern unsigned long
 x86_current_tls();
 
-static char x86_entry_start[];
-static char x86_entry_end[];
+extern char x86_entry_start[] __attribute__((visibility("hidden")));
+extern char x86_entry_end[] __attribute__((visibility("hidden")));
 
 void
 entry_patch_public(void)
