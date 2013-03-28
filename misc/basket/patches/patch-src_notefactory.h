$NetBSD: patch-src_notefactory.h,v 1.1 2013/03/28 21:43:09 joerg Exp $

--- src/notefactory.h.orig	2013-03-28 12:33:12.000000000 +0000
+++ src/notefactory.h
@@ -32,8 +32,6 @@ class QColor;
 class Basket;
 class Note;
 
-enum NoteType::Id;
-
 /** Factory class to create (new, drop, past) or load BasketIem, and eventuelly save them (?)
   * @author Sébastien Laoût
   */
