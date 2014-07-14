$NetBSD: patch-khexedit_lib_kbigbuffer.cpp,v 1.1 2014/07/14 09:57:54 jperkin Exp $

Avoid "error: call of overloaded <func> is ambiguous"

--- khexedit/lib/kbigbuffer.cpp.orig	2005-09-10 08:21:32.000000000 +0000
+++ khexedit/lib/kbigbuffer.cpp
@@ -170,7 +170,7 @@ bool KBigBuffer::ensurePageLoaded( unsig
   if( NoOfFreePages < 1 )
   {
     // free the page which is the furthest away from the page we are loading
-    if( abs(FirstPage-PageIndex) > abs(LastPage-PageIndex) )
+    if( abs((int)FirstPage-(int)PageIndex) > abs((int)LastPage-(int)PageIndex) )
       while( !freePage(FirstPage++) );
     else
       while( !freePage(LastPage--) );
