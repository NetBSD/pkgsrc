$NetBSD: patch-pgame_pfield.c,v 1.1 2013/08/31 14:48:38 joerg Exp $

--- pgame/pfield.c.orig	2013-08-31 14:21:42.000000000 +0000
+++ pgame/pfield.c
@@ -29,7 +29,7 @@
 #include <pfield.h>
 
 
-inline void p_field_clear(pfield *f) {
+void p_field_clear(pfield *f) {
 /* p_field_clear
 
    Clears the playing field to P_CLEAR.   */
@@ -48,7 +48,7 @@ inline void p_field_clear(pfield *f) {
 }
 
 
-inline void p_field_copy(pfield *dest, const pfield *src) {
+void p_field_copy(pfield *dest, const pfield *src) {
 /* p_field_copy
 
    Copies src playing field to the destination playing field given.  */
@@ -183,7 +183,7 @@ void p_field_set(pfield *f, int x, int y
 }
 
 
-inline void _p_field_redraw(pfield *f, int x1, int y1, int x2, int y2, int redraw) {
+static inline void _p_field_redraw(pfield *f, int x1, int y1, int x2, int y2, int redraw) {
 
    int *p;
    int i;
