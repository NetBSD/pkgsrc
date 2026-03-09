$NetBSD: patch-imap_idlemsg.c,v 1.1 2026/03/09 03:19:47 jnemeth Exp $

Fix SunOS build, where "sun" is defined, which clashes with variable naming.

--- imap/idlemsg.c.orig	2024-03-13 02:46:30.000000000 +0000
+++ imap/idlemsg.c
@@ -60,6 +60,11 @@
 #include "idlemsg.h"
 #include "global.h"
 
+/* SunOS defines the macro "sun", which clashes with variable naming here. */
+#ifdef sun
+#undef sun
+#endif
+
 /* generated headers are not necessarily in current directory */
 #include "imap/imap_err.h"
 
