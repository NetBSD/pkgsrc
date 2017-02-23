$NetBSD: patch-src_libcompiler__builtins_build.rs,v 1.1 2017/02/23 09:35:16 jperkin Exp $

Don't build gcc_personality_v0.o on NetBSD.

--- src/libcompiler_builtins/build.rs.orig	2017-02-09 01:37:48.000000000 +0000
+++ src/libcompiler_builtins/build.rs
@@ -251,7 +251,7 @@ fn main() {
             sources.extend(&["x86_64/floatdidf.c", "x86_64/floatdisf.c", "x86_64/floatdixf.c"]);
         }
     } else {
-        if !target.contains("freebsd") {
+        if !target.contains("freebsd") & !target.contains("netbsd") {
             sources.extend(&["gcc_personality_v0.c"]);
         }
 
