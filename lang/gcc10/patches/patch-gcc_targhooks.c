$NetBSD: patch-gcc_targhooks.c,v 1.1 2020/05/10 15:02:44 maya Exp $

PR pkg/53436
netbsd can't handle hidden reference to stack_chk_fail_local.
(note: this code is only happening if targeting i386)

--- gcc/targhooks.c.orig	2018-01-13 18:00:59.000000000 +0000
+++ gcc/targhooks.c
@@ -919,7 +919,7 @@ default_external_stack_protect_fail (voi
 tree
 default_hidden_stack_protect_fail (void)
 {
-#ifndef HAVE_GAS_HIDDEN
+#if !defined(HAVE_GAS_HIDDEN) || defined(__NetBSD__) || defined(__sun)
   return default_external_stack_protect_fail ();
 #else
   tree t = stack_chk_fail_decl;
