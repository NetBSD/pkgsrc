$NetBSD: patch-lib_getline.cc,v 1.1 2025/02/10 08:18:24 pho Exp $

Fix build with clang:

    ./getline.cc:58:7: error: ISO C++17 does not allow 'register' storage class specifier [-Wregister]                                                              
       58 |       register int c = getc (stream);                                  
          |       ^~~~~~~~                                                          

--- lib/getline.cc.orig	2025-02-10 08:16:06.983923000 +0000
+++ lib/getline.cc
@@ -55,7 +55,7 @@ getstr (char **lineptr, size_t *n, FILE *stream, char 
 
   for (;;)
     {
-      register int c = getc (stream);
+      int c = getc (stream);
 
       /* We always want at least one char left in the buffer, since we
          always (unless we get an error while reading the first char)
