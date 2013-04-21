$NetBSD: patch-src_undo.c,v 1.1 2013/04/21 15:40:00 joerg Exp $

--- src/undo.c.orig	2013-03-01 17:40:31.000000000 +0000
+++ src/undo.c
@@ -41,8 +41,7 @@ Lisp_Object pending_boundary;
    (It is possible to record an insertion before or after the fact
    because we don't need to record the contents.)  */
 
-record_insert (beg, length)
-     Lisp_Object beg, length;
+void record_insert(Lisp_Object beg, Lisp_Object length)
 {
   Lisp_Object lbeg, lend;
 
@@ -85,8 +84,7 @@ record_insert (beg, length)
 /* Record that a deletion is about to take place,
    for LENGTH characters at location BEG.  */
 
-record_delete (beg, length)
-     int beg, length;
+void record_delete (int beg, int length)
 {
   Lisp_Object lbeg, lend, sbeg;
   int at_boundary;
@@ -143,7 +141,7 @@ record_change (beg, length)
    Record the file modification date so that when undoing this entry
    we can tell whether it is obsolete because the file was saved again.  */
 
-record_first_change ()
+void record_first_change (void)
 {
   Lisp_Object high, low;
 
@@ -162,9 +160,7 @@ record_first_change ()
 /* Record a change in property PROP (whose old value was VAL)
    for LENGTH characters starting at position BEG in BUFFER.  */
 
-record_property_change (beg, length, prop, value, buffer)
-     int beg, length;
-     Lisp_Object prop, value, buffer;
+void record_property_change (int beg, int length, Lisp_Object prop, Lisp_Object value, Lisp_Object buffer)
 {
   Lisp_Object lbeg, lend, entry;
   struct buffer *obuf = current_buffer;
