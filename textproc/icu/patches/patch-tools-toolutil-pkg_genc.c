$NetBSD: patch-tools-toolutil-pkg_genc.c,v 1.2 2015/04/06 07:22:54 adam Exp $

Older assemblers for Darwin (like the one from Xcode 2.5) do not
have .balign, but they take .align 4 to mean 2^4 = 16 bytes.

--- tools/toolutil/pkg_genc.c.orig	2015-03-27 21:10:56.000000000 +0000
+++ tools/toolutil/pkg_genc.c
@@ -137,7 +137,7 @@ static const struct AssemblyType {
         "#endif\n"
         "\t.data\n"
         "\t.const\n"
-        "\t.balign 16\n"
+        "\t.align 4\n"
         "_%s:\n\n",
 
         ".long ","",HEX_0X
