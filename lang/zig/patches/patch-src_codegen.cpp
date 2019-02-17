$NetBSD: patch-src_codegen.cpp,v 1.1 2019/02/17 12:33:40 maya Exp $

--- src/codegen.cpp.orig	2019-02-17 10:28:53.000000000 +0000
+++ src/codegen.cpp
@@ -184,7 +184,8 @@ CodeGen *codegen_create(Buf *root_src_pa
     // On Darwin/MacOS/iOS, we always link libSystem which contains libc.
     if (g->zig_target.os == OsMacOSX ||
         g->zig_target.os == OsIOS ||
-	g->zig_target.os == OsFreeBSD)
+	g->zig_target.os == OsFreeBSD ||
+	g->zig_target.os == OsNetBSD)
     {
         g->libc_link_lib = create_link_lib(buf_create_from_str("c"));
         g->link_libs_list.append(g->libc_link_lib);
