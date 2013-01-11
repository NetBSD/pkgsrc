$NetBSD: patch-cut-paste.c,v 1.1 2013/01/11 00:00:50 joerg Exp $

--- cut-paste.c.orig	2013-01-10 22:43:42.000000000 +0000
+++ cut-paste.c
@@ -312,7 +312,7 @@ int len;
 			default:	break;
 		}
 	}
-	return;	/* Hopefully, we never reach here */
+	return NULL;	/* Hopefully, we never reach here */
 }
 
 
