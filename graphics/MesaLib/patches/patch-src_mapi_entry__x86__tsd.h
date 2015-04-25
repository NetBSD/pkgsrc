$NetBSD: patch-src_mapi_entry__x86__tsd.h,v 1.1 2015/04/25 11:19:18 tnn Exp $

Fix --enable-glx-tls with clang. From FreeBSD.

--- src/mapi/entry_x86_tsd.h.orig	2015-03-28 18:20:39.000000000 +0000
+++ src/mapi/entry_x86_tsd.h
@@ -59,8 +59,8 @@ __asm__(".balign 32\n"
 #include <string.h>
 #include "u_execmem.h"
 
-static const char x86_entry_start[];
-static const char x86_entry_end[];
+extern const char x86_entry_start[] __attribute__((visibility("hidden")));
+extern const char x86_entry_end[] __attribute__((visibility("hidden")));
 
 void
 entry_patch_public(void)
