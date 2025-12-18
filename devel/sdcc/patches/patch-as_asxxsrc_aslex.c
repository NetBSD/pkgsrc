$NetBSD: patch-as_asxxsrc_aslex.c,v 1.1 2025/12/18 15:43:42 ryoon Exp $

--- as/asxxsrc/aslex.c.orig	2025-12-18 06:15:35.445443633 +0000
+++ as/asxxsrc/aslex.c
@@ -265,7 +265,7 @@ get()
  */
 
 VOID
-unget(c)
+unget(int c)
 {
         if (c)
                 if (ip != ib)
@@ -303,7 +303,7 @@ unget(c)
  */
 
 int
-getmap(d)
+getmap(int d)
 {
         register int c, n, v;
 
