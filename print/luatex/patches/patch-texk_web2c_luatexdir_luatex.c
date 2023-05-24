$NetBSD: patch-texk_web2c_luatexdir_luatex.c,v 1.3 2023/05/24 12:03:35 markd Exp $

1.16.0 -> 1.17.0

--- texk/web2c/luatexdir/luatex.c	2023/05/01 23:50:21	66983
+++ texk/web2c/luatexdir/luatex.c	2023/05/02 15:26:43	66984
@@ -32,9 +32,9 @@
     stick to "0" upto "9" so users can expect a number represented as string.
 */
 
-int luatex_version = 116;
+int luatex_version = 117;
 int luatex_revision = '0';
-const char *luatex_version_string = "1.16.0";
+const char *luatex_version_string = "1.17.0";
 const char *engine_name = my_name;
 
 #include <kpathsea/c-ctype.h>
