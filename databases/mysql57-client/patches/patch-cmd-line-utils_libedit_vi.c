$NetBSD: patch-cmd-line-utils_libedit_vi.c,v 1.1 2018/10/01 00:11:29 sevan Exp $

DragonFly BSD build fix

--- cmd-line-utils/libedit/vi.c.orig	2018-09-30 16:47:49.075991000 -0700
+++ cmd-line-utils/libedit/vi.c	2018-09-30 16:48:41.343701000 -0700
@@ -919,7 +919,7 @@
  * NB: posix implies that we should enter insert mode, however
  * this is against historical precedent...
  */
-#if defined(__weak_reference) && !defined(__FreeBSD__)
+#if defined(__weak_reference) && !defined(__FreeBSD__) && !defined(__DragonFly__)
 __weakref_visible char *my_get_alias_text(const char *)
     __weak_reference(get_alias_text);
 #endif
@@ -928,7 +928,7 @@
 vi_alias(EditLine *el __attribute__((__unused__)),
 	 Int c __attribute__((__unused__)))
 {
-#if defined(__weak_reference) && !defined(__FreeBSD__)
+#if defined(__weak_reference) && !defined(__FreeBSD__) && !defined(__DragonFly__)
 	char alias_name[3];
 	char *alias_text;
 
