$NetBSD: patch-rotate.c,v 1.2 2021/12/30 13:12:24 nia Exp $

Don't cast pointer to int, it no longer even works under Linux/GCC
because this isn't 1995 and 64-bit platforms exist.

--- rotate.c.orig	1998-11-29 21:09:40.000000000 +0000
+++ rotate.c
@@ -510,9 +510,9 @@ morph(int winno, SHAPE* source, SHAPE* d
     {
 /* wheee.. fun with pointer math ... but will it work everywhere? */
 /* eh... what the hell, it works under Linux/GCC */
-      int base=(int)&(source->vertices[0]);
-      int facenum =(int) (source->faces[i]);
-      int sidenum= (facenum-base)/(sizeof(vertex_type));
+      intptr_t base=(intptr_t)&(source->vertices[0]);
+      intptr_t facenum =(intptr_t) (source->faces[i]);
+      intptr_t sidenum= (facenum-base)/(sizeof(vertex_type));
       temp.faces[i]= &temp.vertices[sidenum];
     }
     for(i=0;i<dest->numVert;i++)
