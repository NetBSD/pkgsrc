$NetBSD: patch-main.c,v 1.1 2023/05/20 12:47:47 thorpej Exp $

Add a path prefix to the default boot ROM path until a more comprehensive
solution is implemented upstream.

--- main.c.orig	2023-05-13 00:28:06
+++ main.c	2023-05-20 00:04:49
@@ -1714,7 +1714,11 @@ int main(int argc, char **argv)
    * Default ROM is now OpenNabu (opennabu.bin).
    * You can use actual Nabu firmware with the -4, -8 and -B switches.
    */
-  bios = OPENNABU;
+  bios =
+#ifdef ROM_PATHSPEC
+         ROM_PATHSPEC "/"
+#endif
+	 OPENNABU;
   while (-1 != (e = getopt(argc, argv, "48B:jJS:P:Np:a:b:x:")))
   {
    switch (e)
