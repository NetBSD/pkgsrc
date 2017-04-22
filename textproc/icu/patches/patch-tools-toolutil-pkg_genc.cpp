$NetBSD: patch-tools-toolutil-pkg_genc.cpp,v 1.1 2017/04/22 20:11:45 adam Exp $

Older assemblers for Darwin (like the one from Xcode 2.5) do not
have .balign, but they take .align 4 to mean 2^4 = 16 bytes.

--- tools/toolutil/pkg_genc.cpp.orig	2015-03-27 21:10:56.000000000 +0000
+++ tools/toolutil/pkg_genc.cpp
@@ -139,7 +139,7 @@ static const struct AssemblyType {
         "#endif\n"
         "\t.data\n"
         "\t.const\n"
-        "\t.balign 16\n"
+        "\t.align 4\n"
         "_%s:\n\n",
 
         ".long ","",HEX_0X
