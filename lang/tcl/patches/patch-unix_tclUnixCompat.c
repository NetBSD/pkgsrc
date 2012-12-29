$NetBSD: patch-unix_tclUnixCompat.c,v 1.1 2012/12/29 13:49:12 bsiegert Exp $

This is needed on MirBSD, which does not have the required sysconf
constants.

--- unix/tclUnixCompat.c.orig	Thu Dec 13 16:53:10 2012
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
 	tsdPtr->pbuf = ckalloc(tsdPtr->pbuflen);
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
 	tsdPtr->pbuf = ckalloc(tsdPtr->pbuflen);
 	Tcl_CreateThreadExitHandler(FreePwBuf, NULL);
     }
@@ -380,10 +388,14 @@ TclpGetGrNam(
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
 	tsdPtr->gbuf = ckalloc(tsdPtr->gbuflen);
 	Tcl_CreateThreadExitHandler(FreeGrBuf, NULL);
     }
@@ -460,10 +472,14 @@ TclpGetGrGid(
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
 	tsdPtr->gbuf = ckalloc(tsdPtr->gbuflen);
 	Tcl_CreateThreadExitHandler(FreeGrBuf, NULL);
     }
