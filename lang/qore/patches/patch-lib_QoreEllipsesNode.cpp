$NetBSD: patch-lib_QoreEllipsesNode.cpp,v 1.1 2023/08/08 19:31:04 nros Exp $

* Make sure qore_program_private::get is visible

--- lib/QoreEllipsesNode.cpp.orig	2023-08-06 11:57:14.108415961 +0000
+++ lib/QoreEllipsesNode.cpp
@@ -29,6 +29,7 @@
 */
 
 #include <qore/Qore.h>
+#include <qore/intern/qore_program_private.h>
 
 QoreString QoreEllipsesNode::staticEllipses("...");
 
@@ -42,4 +43,4 @@ int QoreEllipsesNode::parseInitImpl(Qore
     qore_program_private::get(*getProgram())->makeParseException(*loc, "ILLEGAL-ELLIPSES",
         new QoreStringNode("ellipses can only be used as the final or only element in a parameter list"));
     return -1;
-}
\ No newline at end of file
+}
