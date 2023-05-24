$NetBSD: patch-texk_web2c_luatexdir_tex_texnodes.c,v 1.1 2023/05/24 12:03:35 markd Exp $

1.16.0 -> 1.17.0

--- texk/web2c/luatexdir/tex/texnodes.c	2023/05/01 23:50:21	66983
+++ texk/web2c/luatexdir/tex/texnodes.c	2023/05/02 15:26:43	66984
@@ -1203,7 +1203,7 @@ void l_set_whatsit_data(void) {
     the original one as a metatable. After some experiments (that also included
     timing) with these scenarios I decided that a deep copy made no sense, nor
     did nilling. In the end both the shallow copy and the metatable variant were
-    both ok, although the second ons is slower. The most important aspect to keep
+    both ok, although the second one is slower. The most important aspect to keep
     in mind is that references to other nodes in properties no longer can be
     valid for that copy. We could use two tables (one unique and one shared) or
     metatables but that only complicates matters.
