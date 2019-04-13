$NetBSD: patch-src_runtime_defs__openbsd__386.h,v 1.1 2019/04/13 23:09:40 maya Exp $
$OpenBSD: patch-src_runtime_defs_openbsd_386_h,v 1.1 2018/04/05 17:47:30 jsing Exp $

OpenBSD 6.4 needs stack pages to be mapped with MAP_STACK.

Index: src/runtime/defs_openbsd_386.h
--- src/runtime/defs_openbsd_386.h.orig
+++ src/runtime/defs_openbsd_386.h
@@ -14,6 +14,7 @@ enum {
 	MAP_ANON	= 0x1000,
 	MAP_PRIVATE	= 0x2,
 	MAP_FIXED	= 0x10,
+	MAP_STACK	= 0x4000,
 
 	MADV_FREE	= 0x6,
 
