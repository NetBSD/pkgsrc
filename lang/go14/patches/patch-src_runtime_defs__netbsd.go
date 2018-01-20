$NetBSD: patch-src_runtime_defs__netbsd.go,v 1.1 2018/01/20 16:55:25 christos Exp $

 * Fix Struct name Kevent to KeventT.This file is the base of defs_netbsd_XXX 

--- src/runtime/defs_netbsd.go.orig	2015-09-23 04:37:37.000000000 +0000
+++ src/runtime/defs_netbsd.go
@@ -122,4 +122,4 @@ type Itimerval C.struct_itimerval
 type McontextT C.mcontext_t
 type UcontextT C.ucontext_t
 
-type Kevent C.struct_kevent
+type KeventT C.struct_kevent
