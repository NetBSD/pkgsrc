$NetBSD: patch-opensync_opensync__group.c,v 1.1 2016/02/01 17:10:38 richard Exp $
Recent versions of Illumos implement flock()

--- opensync/opensync_group.c.orig	2007-03-27 11:49:18.000000000 +0000
+++ opensync/opensync_group.c
@@ -26,10 +26,10 @@
 extern int errno;
 
 /*
- * On Solaris no flock function exists,
- * we must implenet it here
+ * On Solaris if no flock function exists,
+ * we must implement it here
  */
-#ifdef SOLARIS
+#if defined(SOLARIS) && !defined(LOCK_EX)
 
 #define LOCK_SH 1
 #define LOCK_EX 2
