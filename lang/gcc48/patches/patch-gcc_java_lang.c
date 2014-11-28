$NetBSD: patch-gcc_java_lang.c,v 1.2 2014/11/28 09:57:32 obache Exp $

--- gcc/java/lang.c.orig	2013-01-10 20:38:27.000000000 +0000
+++ gcc/java/lang.c
@@ -920,4 +920,12 @@ java_eh_personality (void)
   return java_eh_personality_decl;
 }
 
+#ifdef __OpenBSD__
+const char *
+fname_as_string(int pretty_p __attribute__((__unused__)))
+{
+	return NULL;
+}
+#endif
+
 #include "gt-java-lang.h"
