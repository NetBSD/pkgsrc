$NetBSD: patch-scripts_hexdump.c,v 1.2 2017/06/17 19:45:28 joerg Exp $

GNU as accepts .type without comma, LLVM is stricter.

Avoid pushing character array with 8M+ elements through the compiler
on NetBSD as well.

--- scripts/hexdump.c.orig	2017-04-05 11:02:21.000000000 +0000
+++ scripts/hexdump.c
@@ -48,7 +48,7 @@ main(int argc, char **argv)
 	}
 
 	fprintf(fo, "#ifndef __STRICT_ANSI__\n");
-	fprintf(fo, "#if defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__)\n");
+	fprintf(fo, "#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)\n");
 	fprintf(fo, "#if !defined(__ICC) && !defined(__ANDROID__)\n");
 	fprintf(fo, "#define HAVE_INCBIN\n");
 	fprintf(fo, "#endif\n");
@@ -97,7 +97,7 @@ main(int argc, char **argv)
 		fprintf(fo, "extern const char fz_%s[];\n", filename);
 		fprintf(fo, "asm(\".section .rodata\");\n");
 		fprintf(fo, "asm(\".global fz_%s\");\n", filename);
-		fprintf(fo, "asm(\".type fz_%s STT_OBJECT\");\n", filename);
+		fprintf(fo, "asm(\".type fz_%s, STT_OBJECT\");\n", filename);
 		fprintf(fo, "asm(\".size fz_%s, %d\");\n", filename, size);
 		fprintf(fo, "asm(\".balign 64\");\n");
 		fprintf(fo, "asm(\"fz_%s:\");\n", filename);
