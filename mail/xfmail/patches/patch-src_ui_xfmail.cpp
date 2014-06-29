$NetBSD: patch-src_ui_xfmail.cpp,v 1.1 2014/06/29 05:25:48 dholland Exp $

Remove pointless references to sys_nerr.

--- src/ui/xfmail.cpp~	2004-01-02 04:05:37.000000000 +0000
+++ src/ui/xfmail.cpp
@@ -185,12 +185,6 @@ int display_msg(int flags, char *title, 
 			errno = 0;
 		}
 #else
-	#ifdef  HAVE_SYS_NERR
-		if((errno > 0) && (errno < sys_nerr)) {
-			strncpy(errstr, strerror(errno), 63);
-			errno = 0;
-		}
-	#else
 		if(errno > 0) {
 			if(strerror(errno))
 				strncpy(errstr, strerror(errno), 63);
@@ -198,7 +192,6 @@ int display_msg(int flags, char *title, 
 				sprintf(errstr, "Unknown Error %d", errno);
 			errno = 0;
 		}
-	#endif
 #endif
 		else
 			strcpy(errstr, "ERROR");
