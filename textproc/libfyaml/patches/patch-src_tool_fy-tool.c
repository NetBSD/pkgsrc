$NetBSD: patch-src_tool_fy-tool.c,v 1.1 2022/12/08 19:16:20 khorben Exp $

getopt_long_only is not very portable; use getopt_long instead

--- src/tool/fy-tool.c.orig	2022-12-08 19:03:03.058455798 +0000
+++ src/tool/fy-tool.c
@@ -1475,7 +1475,7 @@ int main(int argc, char *argv[])
 		     (STRIP_DOC_DEFAULT ? FYECF_STRIP_DOC : 0);
 	apply_mode_flags(MODE_DEFAULT, &emit_flags);
 
-	while ((opt = getopt_long_only(argc, argv,
+	while ((opt = getopt_long(argc, argv,
 					"I:" "d:" "i:" "w:" "rsc" "C:" "m:" "V" "f:" "t:" "T:F:" "j:" "qhvl",
 					lopts, &lidx)) != -1) {
 		switch (opt) {
