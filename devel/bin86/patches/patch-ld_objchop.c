$NetBSD: patch-ld_objchop.c,v 1.1 2015/02/23 18:20:21 joerg Exp $

--- ld/objchop.c.orig	2015-02-22 19:55:07.000000000 +0000
+++ ld/objchop.c
@@ -1,17 +1,8 @@
-
+#include <stdint.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include "x86_aout.h"
 
-#ifndef __OUT_OK
-
-main()
-{
-   fprintf(stderr, "Compile error: struct exec invalid\n");
-   exit(1);
-}
-
-#else
-
 FILE * ifd;
 struct exec header;
 
@@ -44,7 +35,7 @@ char ** argv;
    ofd = fopen(argv[4], "w");
    if( ofd == 0 ) fatal("Cannot open output file");
 
-   fprintf(ofd, "TEXT_SIZE=%ld\nDATA_SIZE=%ld\nBSS_SIZE=%ld\nALLOC_SIZE=%ld\n",
+   fprintf(ofd, "TEXT_SIZE=%"PRId32"\nDATA_SIZE=%"PRId32"\nBSS_SIZE=%"PRId32"\nALLOC_SIZE=%"PRId32"\n",
            header.a_text, header.a_data, header.a_bss, header.a_total);
 
    fclose(ofd);
@@ -83,5 +74,3 @@ char * str;
    fprintf(stderr, "objchop: %s\n", str);
    exit(2);
 }
-
-#endif
