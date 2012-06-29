$NetBSD: patch-xml2cmp_source_support_list.hxx,v 1.1 2012/06/29 12:36:39 joerg Exp $

--- xml2cmp/source/support/list.hxx.orig	2012-06-23 16:45:20.000000000 +0000
+++ xml2cmp/source/support/list.hxx
@@ -231,7 +231,7 @@ DynamicList<XY>::insert(unsigned pos, XY
     if ( pos > this->len )
       return;
 
-    checkSize(this->len+2);
+    this->checkSize(this->len+2);
     memmove(this->inhalt[pos+1], this->inhalt[pos], (this->len-pos) * sizeof(XY*) );
     this->inhalt[pos] = elem_;
     this->len++;
