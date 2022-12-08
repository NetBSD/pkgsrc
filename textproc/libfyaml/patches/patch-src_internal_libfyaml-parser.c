$NetBSD: patch-src_internal_libfyaml-parser.c,v 1.1 2022/12/08 19:16:20 khorben Exp $

getopt_long_only is not very portable; use getopt_long instead

--- src/internal/libfyaml-parser.c.orig	2022-12-08 19:03:44.942254815 +0000
+++ src/internal/libfyaml-parser.c
@@ -3822,7 +3822,7 @@ int main(int argc, char *argv[])
 
 	fy_valgrind_check(&argc, &argv);
 
-	while ((opt = getopt_long_only(argc, argv, "I:m:i:w:d:rsc:C:D:M:W:S:qh", lopts, &lidx)) != -1) {
+	while ((opt = getopt_long(argc, argv, "I:m:i:w:d:rsc:C:D:M:W:S:qh", lopts, &lidx)) != -1) {
 		switch (opt) {
 		case 'I':
 			tmp = alloca(strlen(cfg.search_path) + 1 + strlen(optarg) + 1);
