$NetBSD: patch-fmemopen.c,v 1.1 2026/03/31 13:57:50 khorben Exp $

Removes a confusion between the opaque type fpos_t and off_t.
Fixes the build on NetBSD.

--- fmemopen.c.orig	2026-01-22 16:28:50.000000000 +0000
+++ fmemopen.c
@@ -53,7 +53,7 @@ static int writefn(void *handler, const 
   return size;
 }
 
-static fpos_t seekfn(void *handler, fpos_t offset, int whence) {
+static off_t seekfn(void *handler, off_t offset, int whence) {
   size_t pos;
   fmem_t *mem = handler;
 
@@ -83,7 +83,7 @@ static fpos_t seekfn(void *handler, fpos
   }
 
   mem->pos = pos;
-  return (fpos_t)pos;
+  return (off_t)pos;
 }
 
 static int closefn(void *handler) {
@@ -92,7 +92,8 @@ static int closefn(void *handler) {
 }
 
 FILE *fmemopen(void *buf, size_t size, const char *mode) {
-  #pragma unused(mode)
+  (void) mode;
+
   // This data is released on fclose.
   fmem_t* mem = (fmem_t *) malloc(sizeof(fmem_t));
 
