$NetBSD: patch-src_vterm.c,v 1.1 2022/04/20 17:14:20 nia Exp $

CVE-2018-20786 fix from vim cd929f7ba8cc5b6d6dcf35c8b34124e969fed6b8

--- src/vterm.c.orig	2020-08-22 14:54:34.000000000 +0000
+++ src/vterm.c
@@ -37,6 +37,8 @@ VTerm *vterm_new_with_allocator(int rows
   /* Need to bootstrap using the allocator function directly */
   VTerm *vt = (*funcs->malloc)(sizeof(VTerm), allocdata);
 
+  if (vt == NULL)
+    return NULL;
   vt->allocator = funcs;
   vt->allocdata = allocdata;
 
@@ -51,6 +53,12 @@ VTerm *vterm_new_with_allocator(int rows
   vt->parser.strbuffer_len = 64;
   vt->parser.strbuffer_cur = 0;
   vt->parser.strbuffer = vterm_allocator_malloc(vt, vt->parser.strbuffer_len);
+  if (vt->parser.strbuffer == NULL)
+  {
+    vterm_allocator_free(vt, vt);
+    return NULL;
+  }
+ 
 
   vt->outfunc = NULL;
   vt->outdata = NULL;
@@ -58,9 +66,22 @@ VTerm *vterm_new_with_allocator(int rows
   vt->outbuffer_len = 64;
   vt->outbuffer_cur = 0;
   vt->outbuffer = vterm_allocator_malloc(vt, vt->outbuffer_len);
+  if (vt->outbuffer == NULL)
+  {
+    vterm_allocator_free(vt, vt->parser.strbuffer);
+    vterm_allocator_free(vt, vt);
+    return NULL;
+  }
 
   vt->tmpbuffer_len = 64;
   vt->tmpbuffer = vterm_allocator_malloc(vt, vt->tmpbuffer_len);
+  if (vt->tmpbuffer == NULL)
+  {
+    vterm_allocator_free(vt, vt->outbuffer);
+    vterm_allocator_free(vt, vt->parser.strbuffer);
+    vterm_allocator_free(vt, vt);
+    return NULL;
+  }
 
   return vt;
 }
@@ -85,9 +106,13 @@ INTERNAL void *vterm_allocator_malloc(VT
   return (*vt->allocator->malloc)(size, vt->allocdata);
 }
 
+/*
+ * Free "ptr" unless it is NULL.
+ */
 INTERNAL void vterm_allocator_free(VTerm *vt, void *ptr)
 {
-  (*vt->allocator->free)(ptr, vt->allocdata);
+  if (ptr)
+    (*vt->allocator->free)(ptr, vt->allocdata);
 }
 
 void vterm_get_size(const VTerm *vt, int *rowsp, int *colsp)
