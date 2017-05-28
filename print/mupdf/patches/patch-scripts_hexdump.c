$NetBSD: patch-scripts_hexdump.c,v 1.1 2017/05/28 12:42:21 rumko Exp $

https://bugs.ghostscript.com/show_bug.cgi?id=696828
Get rid of "error: unexpected token in '.type' directive" on fbsd

--- scripts/hexdump.c.orig	2017-04-05 11:02:21.000000000 +0000
+++ scripts/hexdump.c
@@ -48,7 +48,7 @@ main(int argc, char **argv)
 	}
 
 	fprintf(fo, "#ifndef __STRICT_ANSI__\n");
-	fprintf(fo, "#if defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__)\n");
+	fprintf(fo, "#if defined(__linux__) || defined(__OpenBSD__)\n");
 	fprintf(fo, "#if !defined(__ICC) && !defined(__ANDROID__)\n");
 	fprintf(fo, "#define HAVE_INCBIN\n");
 	fprintf(fo, "#endif\n");
