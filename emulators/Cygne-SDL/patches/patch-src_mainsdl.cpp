$NetBSD: patch-src_mainsdl.cpp,v 1.1 2013/04/13 19:08:27 dholland Exp $

Disable blitter modes 2 and 3 on non-i386 unless/until someone provides
non-asm code for them (see ddrawsdl.cpp / patch-ac)

--- src/mainsdl.cpp~	2002-03-26 16:12:36.000000000 +0000
+++ src/mainsdl.cpp
@@ -322,13 +322,23 @@ int main(int argc, char *argv[])
 	for (i=0; (i < argc || argv[i] != NULL); i++) {
 		
 		if(strcmp(argv[i], "-double") == 0) {
+#if defined(__i386__)
 			fScreenSize = 2;
 			fBlitterMode = 3;
+#else
+			fprintf(stderr, "-double is not supported on this platform\n");
+			exit(1);
+#endif
 		}
 		
 		if(strcmp(argv[i], "-scanline") == 0) {
+#if defined(__i386__)
 			fScreenSize = 2;
 			fBlitterMode = 2;
+#else
+			fprintf(stderr, "-scanline is not supported on this platform\n");
+			exit(1);
+#endif
 		}
 		
 		if (strncmp(argv[i], "-h", 2) == 0) {
