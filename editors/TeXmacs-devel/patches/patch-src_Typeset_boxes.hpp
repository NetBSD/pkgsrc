$NetBSD: patch-src_Typeset_boxes.hpp,v 1.1 2013/08/13 10:21:35 joerg Exp $

--- src/Typeset/boxes.hpp.orig	2012-07-09 15:05:21.000000000 +0000
+++ src/Typeset/boxes.hpp
@@ -250,7 +250,7 @@ public:
   friend struct lazy_paragraph_rep;
   friend class  phrase_box_rep;
   friend class  remember_box_rep;
-  friend void make_eps (url dest, box b, int dpi= 600);
+  friend void make_eps (url dest, box b, int dpi);
 };
 ABSTRACT_NULL_CODE(box);
 
