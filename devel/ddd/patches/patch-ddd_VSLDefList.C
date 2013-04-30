$NetBSD: patch-ddd_VSLDefList.C,v 1.1 2013/04/30 22:15:22 joerg Exp $

--- ddd/VSLDefList.C.orig	2013-04-30 19:33:09.000000000 +0000
+++ ddd/VSLDefList.C
@@ -60,7 +60,7 @@ const Box *VSLDefList::eval(Box *arg) co
     {
 	std::ostringstream s;
 	s << *arg;
-	VSLLib::eval_error("no suiting definition for " + f_name() + s);
+	VSLLib::eval_error("no suiting definition for " + f_name() + s.str().c_str());
     }
 
     return d ? d->eval(arg) : 0;
