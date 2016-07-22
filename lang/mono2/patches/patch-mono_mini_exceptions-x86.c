$NetBSD: patch-mono_mini_exceptions-x86.c,v 1.1 2016/07/22 12:21:05 jperkin Exp $

Remove obsolete and unused SunOS code.

--- mono/mini/exceptions-x86.c.orig	2012-01-30 18:13:39.000000000 +0000
+++ mono/mini/exceptions-x86.c
@@ -895,7 +895,7 @@ mono_arch_find_jit_info (MonoDomain *dom
 	return FALSE;
 }
 
-#ifdef __sun
+#ifdef __notsun
 #define REG_EAX EAX
 #define REG_EBX EBX
 #define REG_ECX ECX
