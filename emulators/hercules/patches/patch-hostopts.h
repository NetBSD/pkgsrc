$NetBSD: patch-hostopts.h,v 1.2 2012/03/25 05:27:43 ryoon Exp $

--- hostopts.h.orig	2010-01-08 22:56:27.000000000 +0000
+++ hostopts.h
@@ -272,7 +272,7 @@
 /*-------------------------------------------------------------------*/
 /* Hard-coded FreeBSD-specific features and options...               */
 /*-------------------------------------------------------------------*/
-#elif defined(__FreeBSD__)              /* "FreeBSD" options         */
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)/* "BSD" options    */
 
 #define DLL_IMPORT   extern
 #define DLL_EXPORT
@@ -295,6 +295,14 @@
 #undef  OPTION_EXTCURS                  /* Normal cursor handling    */
 
 
+/* These should become configure checks */
+# if defined(__NetBSD__)
+#  define OPTION_SCSI_TAPE                /* SCSI tape support         */
+# endif
+# if !defined(SOL_TCP)
+#  define SOL_TCP	IPPROTO_TCP
+# endif
+
 /*-------------------------------------------------------------------*/
 /* GNU Linux options...                                              */
 /*-------------------------------------------------------------------*/
