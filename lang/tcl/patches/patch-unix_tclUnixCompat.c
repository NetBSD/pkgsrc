$NetBSD: patch-unix_tclUnixCompat.c,v 1.2 2021/01/20 20:38:49 adam Exp $

This is needed on MirBSD, which does not have the required sysconf
constants.

--- unix/tclUnixCompat.c.orig	2020-12-11 17:46:23.000000000 +0000
+++ unix/tclUnixCompat.c
@@ -197,10 +197,14 @@ TclpGetPwNam(
      */
 
     if (tsdPtr->pbuf == NULL) {
+#ifdef _SC_GETPW_R_SIZE_MAX
 	tsdPtr->pbuflen = (int) sysconf(_SC_GETPW_R_SIZE_MAX);
 	if (tsdPtr->pbuflen < 1) {
+#endif
 	    tsdPtr->pbuflen = 1024;
+#ifdef _SC_GETPW_R_SIZE_MAX
 	}
+#endif
 	tsdPtr->pbuf = (char *)ckalloc(tsdPtr->pbuflen);
 	Tcl_CreateThreadExitHandler(FreePwBuf, NULL);
     }
@@ -277,10 +281,14 @@ TclpGetPwUid(
      */
 
     if (tsdPtr->pbuf == NULL) {
+#ifdef _SC_GETPW_R_SIZE_MAX
 	tsdPtr->pbuflen = (int) sysconf(_SC_GETPW_R_SIZE_MAX);
 	if (tsdPtr->pbuflen < 1) {
+#endif
 	    tsdPtr->pbuflen = 1024;
+#ifdef _SC_GETPW_R_SIZE_MAX
 	}
+#endif
 	tsdPtr->pbuf = (char *)ckalloc(tsdPtr->pbuflen);
 	Tcl_CreateThreadExitHandler(FreePwBuf, NULL);
     }
@@ -381,10 +389,14 @@ TclpGetGrNam(
      */
 
     if (tsdPtr->gbuf == NULL) {
+#ifdef _SC_GETGR_R_SIZE_MAX
 	tsdPtr->gbuflen = (int) sysconf(_SC_GETGR_R_SIZE_MAX);
 	if (tsdPtr->gbuflen < 1) {
+#endif
 	    tsdPtr->gbuflen = 1024;
+#ifdef _SC_GETGR_R_SIZE_MAX
 	}
+#endif
 	tsdPtr->gbuf = (char *)ckalloc(tsdPtr->gbuflen);
 	Tcl_CreateThreadExitHandler(FreeGrBuf, NULL);
     }
@@ -461,10 +473,14 @@ TclpGetGrGid(
      */
 
     if (tsdPtr->gbuf == NULL) {
+#ifdef _SC_GETGR_R_SIZE_MAX
 	tsdPtr->gbuflen = (int) sysconf(_SC_GETGR_R_SIZE_MAX);
 	if (tsdPtr->gbuflen < 1) {
+#endif
 	    tsdPtr->gbuflen = 1024;
+#ifdef _SC_GETGR_R_SIZE_MAX
 	}
+#endif
 	tsdPtr->gbuf = (char *)ckalloc(tsdPtr->gbuflen);
 	Tcl_CreateThreadExitHandler(FreeGrBuf, NULL);
     }
