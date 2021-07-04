$NetBSD: patch-aq,v 1.2 2021/07/04 07:57:13 jnemeth Exp $

--- sendmail/conf.h.orig	2020-05-19 19:54:33.000000000 +0000
+++ sendmail/conf.h
@@ -236,6 +236,10 @@ struct rusage;	/* forward declaration to
 # define PIPELINING	1	/* SMTP PIPELINING */
 #endif
 
+#ifndef NAMED_RESN
+# define NAMED_RESN	1	/* res_n* functions are available */
+#endif
+
 /**********************************************************************
 **  End of site-specific configuration.
 **********************************************************************/
