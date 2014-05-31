$NetBSD: patch-gcc_go_go-lang.c,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- gcc/go/go-lang.c.orig	2013-12-12 02:29:08.000000000 +0000
+++ gcc/go/go-lang.c
@@ -457,6 +457,12 @@ go_localize_identifier (const char *iden
   return identifier_to_locale (ident);
 }
 
+const char *
+fname_as_string(int pretty_p __attribute__((__unused__)))
+{
+	return NULL;
+}
+
 #undef LANG_HOOKS_NAME
 #undef LANG_HOOKS_INIT
 #undef LANG_HOOKS_OPTION_LANG_MASK
