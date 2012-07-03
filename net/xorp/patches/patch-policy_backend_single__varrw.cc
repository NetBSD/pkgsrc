$NetBSD: patch-policy_backend_single__varrw.cc,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- policy/backend/single_varrw.cc.orig	2009-01-05 18:31:06.000000000 +0000
+++ policy/backend/single_varrw.cc
@@ -70,7 +70,7 @@ SingleVarRW::read(const Id& id)
 
 	// out of luck...
 	if(!e)
-	    xorp_throw(SingleVarRWErr, "Unable to read variable " + id);
+	    xorp_throw(SingleVarRWErr, c_format("Unable to read variable %d", id));
     }
 
     return *e;
