$NetBSD: patch-include_qore_QoreFile.h,v 1.1 2014/12/30 15:39:51 wiz Exp $
* Fixes build on NetBSD 6
http://sourceforge.net/p/qore/code/6803/
--- include/qore/QoreFile.h.orig	2013-03-05 09:44:51.000000000 +0000
+++ include/qore/QoreFile.h
@@ -34,6 +34,10 @@
 
 #include <string>
 
+#ifdef getchar
+#undef getchar
+#endif
+
 class QoreTermIOS;
 class Queue;
 
