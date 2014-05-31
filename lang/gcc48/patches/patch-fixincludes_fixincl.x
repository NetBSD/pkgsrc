$NetBSD: patch-fixincludes_fixincl.x,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- fixincludes/fixincl.x.orig	2013-05-31 11:43:36.000000000 +0000
+++ fixincludes/fixincl.x
@@ -6154,11 +6154,11 @@ static const char* apzSolaris_Complex_Cx
     "-e", "/#if[ \t]*!defined(__cplusplus)/c\\\n\
 #ifdef\t__cplusplus\\\n\
 extern \"C\" {\\\n\
-#endif",
+#endif\\\n",
     "-e", "/#endif[ \t]*\\/\\* !defined(__cplusplus) \\*\\//c\\\n\
 #ifdef\t__cplusplus\\\n\
 }\\\n\
-#endif",
+#endif\\\n",
     (char*)NULL };
 
 /* * * * * * * * * * * * * * * * * * * * * * * * * *
