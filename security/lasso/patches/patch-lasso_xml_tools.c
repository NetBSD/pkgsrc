$NetBSD: patch-lasso_xml_tools.c,v 1.1 2018/07/31 12:39:34 jperkin Exp $

Set _XOPEN_SOURCE correctly.

--- lasso/xml/tools.c.orig	2016-02-18 23:11:15.312239445 +0000
+++ lasso/xml/tools.c
@@ -28,7 +28,9 @@
  */
 #define _DEFAULT_SOURCE
 /* permit importation of strptime for glibc2 */
+#if !defined(__sun)
 #define _XOPEN_SOURCE
+#endif
 /* permit importation of timegm for glibc2, wait for people to complain it does not work on their
  * system. */
 #define _BSD_SOURCE
