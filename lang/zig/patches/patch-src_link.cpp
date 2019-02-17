$NetBSD: patch-src_link.cpp,v 1.1 2019/02/17 12:33:40 maya Exp $

--- src/link.cpp.orig	2019-02-17 10:28:53.000000000 +0000
+++ src/link.cpp
@@ -198,6 +198,9 @@ static Buf *get_dynamic_linker_path(Code
     if (g->zig_target.os == OsFreeBSD) {
         return buf_create_from_str("/libexec/ld-elf.so.1");
     }
+    if (g->zig_target.os == OsNetBSD) {
+        return buf_create_from_str("/libexec/ld.elf_so");
+    }
     if (g->is_native_target && g->zig_target.arch.arch == ZigLLVM_x86_64) {
         static const char *ld_names[] = {
             "ld-linux-x86-64.so.2",
@@ -263,10 +266,13 @@ static void construct_linker_job_elf(Lin
     if (lj->link_in_crt) {
         const char *crt1o;
         const char *crtbegino;
-        if (g->is_static) {
+        if (g->zig_target.os == OsNetBSD) {
+	    crt1o = "crt0.o";
+	    crtbegino = "crtbegin.o";
+	} else if (g->is_static) {
             crt1o = "crt1.o";
             crtbegino = "crtbeginT.o";
-        } else {
+	} else {
             crt1o = "Scrt1.o";
             crtbegino = "crtbegin.o";
         }
