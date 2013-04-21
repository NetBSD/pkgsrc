$NetBSD: patch-src_marker.c,v 1.1 2013/04/21 15:40:00 joerg Exp $

--- src/marker.c.orig	1994-10-21 04:20:33.000000000 +0000
+++ src/marker.c
@@ -221,8 +221,7 @@ DEFUN ("marker-point-type", Fmarker_poin
    so we must be careful to ignore and preserve mark bits,
    including those in chain fields of markers.  */
 
-unchain_marker (marker)
-     register Lisp_Object marker;
+void unchain_marker (Lisp_Object marker)
 {
   register Lisp_Object tail, prev, next;
   register Lisp_Object_Int omark;
