$NetBSD: patch-src_Typeset_boxes.hpp,v 1.1 2013/08/13 10:21:35 joerg Exp $

--- src/Typeset/boxes.hpp.orig	2013-08-12 16:27:23.000000000 +0000
+++ src/Typeset/boxes.hpp
@@ -249,7 +249,7 @@ public:
   friend struct lazy_paragraph_rep;
   friend class  phrase_box_rep;
   friend class  remember_box_rep;
-  friend void make_eps (url dest, box b, int dpi= 600);
+  friend void make_eps (url dest, box b, int dpi);
 };
 ABSTRACT_NULL_CODE(box);
 
