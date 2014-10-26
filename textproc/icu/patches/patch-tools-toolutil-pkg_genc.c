$NetBSD: patch-tools-toolutil-pkg_genc.c,v 1.1 2014/10/26 19:46:48 bsiegert Exp $

--- tools/toolutil/pkg_genc.c.orig	2014-10-25 17:58:50.000000000 +0000
+++ tools/toolutil/pkg_genc.c
@@ -125,13 +125,15 @@ static const struct AssemblyType {

         ".long ","",HEX_0X
     },
+    // Older assemblers for Darwin (like the one from Xcode 2.5) do not
+    // have .balign, but they take .align 4 to mean 2^4 = 16 bytes.
     {"gcc-darwin",
         /*"\t.section __TEXT,__text,regular,pure_instructions\n"
         "\t.section __TEXT,__picsymbolstub1,symbol_stubs,pure_instructions,32\n"*/
         ".globl _%s\n"
         "\t.data\n"
         "\t.const\n"
-        "\t.balign 16\n"
+        "\t.align 4\n"
         "_%s:\n\n",

         ".long ","",HEX_0X
