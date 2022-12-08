$NetBSD: patch-test_libfyaml-test.c,v 1.1 2022/12/08 19:16:20 khorben Exp $

getopt_long_only is not very portable; use getopt_long instead

--- test/libfyaml-test.c.orig	2022-12-08 19:03:14.553897741 +0000
+++ test/libfyaml-test.c
@@ -66,7 +66,7 @@ int main(int argc, char *argv[])
 
 	fy_valgrind_check(&argc, &argv);
 
-	while ((opt = getopt_long_only(argc, argv, "qh", lopts, &lidx)) != -1) {
+	while ((opt = getopt_long(argc, argv, "qh", lopts, &lidx)) != -1) {
 		switch (opt) {
 		case 'q':
 			quiet = true;
