$NetBSD: patch-gcc_java_lang.c,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- gcc/java/lang.c.orig	2013-01-10 20:38:27.000000000 +0000
+++ gcc/java/lang.c
@@ -920,4 +920,10 @@ java_eh_personality (void)
   return java_eh_personality_decl;
 }
 
+const char *
+fname_as_string(int pretty_p __attribute__((__unused__)))
+{
+	return NULL;
+}
+
 #include "gt-java-lang.h"
