$NetBSD: patch-src_JavaCat_Class.cpp,v 1.1 2013/04/29 21:17:48 joerg Exp $

--- src/JavaCat/Class.cpp.orig	2013-04-29 20:02:00.000000000 +0000
+++ src/JavaCat/Class.cpp
@@ -601,11 +601,11 @@ bool Class::reverse(ClassContainer * con
 	  if (CurrentArtifact->associatedClasses().isEmpty()) {
 	    // first association, to set artifact def
 	    Package * pack = (Package *) cl->parent();
-	    UmlArtifact * nullptr = 0;
+	    UmlArtifact * my_nullptr = 0;
 	    
 	    CurrentArtifact->addAssociatedClass(cl_uml);
 	    cl_uml->need_artifact(pack->get_imports(), pack->is_java_lang_added(),
-				  pack->get_static_imports(), path, nullptr);
+				  pack->get_static_imports(), path, my_nullptr);
 	  }
 	  else
 	    CurrentArtifact->addAssociatedClass(cl_uml);
