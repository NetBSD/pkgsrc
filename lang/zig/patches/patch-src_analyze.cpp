$NetBSD: patch-src_analyze.cpp,v 1.1 2019/02/17 12:33:40 maya Exp $

--- src/analyze.cpp.orig	2019-02-17 10:28:53.000000000 +0000
+++ src/analyze.cpp
@@ -4732,7 +4732,8 @@ void find_libc_include_path(CodeGen *g) 
             }
         } else if (g->zig_target.os == OsLinux ||
             g->zig_target.os == OsMacOSX ||
-            g->zig_target.os == OsFreeBSD)
+            g->zig_target.os == OsFreeBSD ||
+	    g->zig_target.os == OsNetBSD)
         {
             g->libc_include_dir = get_posix_libc_include_path();
         } else {
@@ -4781,7 +4782,7 @@ void find_libc_lib_path(CodeGen *g) {
 
         } else if (g->zig_target.os == OsLinux) {
             g->libc_lib_dir = get_linux_libc_lib_path("crt1.o");
-        } else if (g->zig_target.os == OsFreeBSD) {
+        } else if ((g->zig_target.os == OsFreeBSD) || (g->zig_target.os == OsNetBSD)) {
             g->libc_lib_dir = buf_create_from_str("/usr/lib");
         } else {
             zig_panic("Unable to determine libc lib path.");
@@ -4795,7 +4796,7 @@ void find_libc_lib_path(CodeGen *g) {
             return;
         } else if (g->zig_target.os == OsLinux) {
             g->libc_static_lib_dir = get_linux_libc_lib_path("crtbegin.o");
-        } else if (g->zig_target.os == OsFreeBSD) {
+        } else if ((g->zig_target.os == OsFreeBSD) || (g->zig_target.os == OsNetBSD)) {
             g->libc_static_lib_dir = buf_create_from_str("/usr/lib");
         } else {
             zig_panic("Unable to determine libc static lib path.");
@@ -6710,7 +6711,9 @@ LinkLib *add_link_lib(CodeGen *g, Buf *n
     if (is_libc && g->libc_link_lib != nullptr)
         return g->libc_link_lib;
 
-    if (g->enable_cache && is_libc && g->zig_target.os != OsMacOSX && g->zig_target.os != OsIOS && g->zig_target.os != OsFreeBSD) {
+    if (g->enable_cache && is_libc && g->zig_target.os != OsMacOSX &&
+        g->zig_target.os != OsIOS && g->zig_target.os != OsFreeBSD &&
+	g->zig_target.os != OsNetBSD) {
         fprintf(stderr, "TODO linking against libc is currently incompatible with `--cache on`.\n"
         "Zig is not yet capable of determining whether the libc installation has changed on subsequent builds.\n");
         exit(1);
