$NetBSD: patch-imap_idlemsg.c,v 1.1 2026/03/09 03:07:50 jnemeth Exp $

Fix SunOS build, where "sun" is defined, which clashes with variable naming.

--- imap/idlemsg.c.orig	2024-08-16 01:23:44.000000000 +0000
+++ imap/idlemsg.c
@@ -62,6 +62,11 @@
 #include "xunlink.h"
 #include "util.h"
 
+/* SunOS defines the macro "sun", which clashes with variable naming here. */
+#ifdef sun
+#undef sun
+#endif
+
 /* generated headers are not necessarily in current directory */
 #include "imap/imap_err.h"
 
