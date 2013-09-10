$NetBSD: patch-src_lib_sfio_Stdio__b_sfstdio.c,v 1.1 2013/09/10 14:18:11 joerg Exp $

--- src/lib/sfio/Stdio_b/sfstdio.c.orig	2013-09-10 12:08:39.000000000 +0000
+++ src/lib/sfio/Stdio_b/sfstdio.c
@@ -670,7 +670,7 @@ int main()
 	printf("extern int\t\tvprintf _ARG_((const char* , va_list));\n");
 	printf("extern int\t\tvscanf _ARG_((const char* , va_list));\n");
 	printf("extern int\t\tvsprintf _ARG_((char*, const char* , va_list));\n");
-	printf("extern int\t\tvsscanf _ARG_((char*, const char* , va_list));\n");
+	printf("extern int\t\tvsscanf _ARG_((const char*, const char* , va_list));\n");
 	printf("#if __cplusplus\n");
 	printf("}\n");
 	printf("#endif\n\n");
