$NetBSD: patch-tools_memory.c,v 1.1 2015/04/26 13:30:58 joerg Exp $

--- tools/memory.c.orig	2015-04-26 12:09:00.000000000 +0000
+++ tools/memory.c
@@ -165,7 +165,7 @@ static void print_ptr(memchunk *mc, int 
 static void print_ptrs(char *msg)
 {  int bucket,i,n=0;
 
-   fprintf(stdout, msg);
+   fprintf(stdout, "%s", msg);
 
    for(bucket=0; bucket<64; bucket++)
       for(i=0; i<phCnt[bucket]; i++)
