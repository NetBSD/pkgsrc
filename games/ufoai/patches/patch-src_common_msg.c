$NetBSD: patch-src_common_msg.c,v 1.1 2015/03/31 15:40:03 joerg Exp $

--- src/common/msg.c.orig	2015-03-26 15:32:50.000000000 +0000
+++ src/common/msg.c
@@ -316,9 +316,6 @@ void MSG_V_WriteFormat (sizebuf_t * sb, 
 			Com_Error(ERR_DROP, "WriteFormat: Unknown type!");
 		}
 	}
-	/* Too many arguments for the given format; too few cause crash above */
-	if (!ap)
-		Com_Error(ERR_DROP, "WriteFormat: Too many arguments!");
 }
 
 /**
@@ -662,9 +659,6 @@ void MSG_V_ReadFormat (sizebuf_t * msg_r
 			Com_Error(ERR_DROP, "ReadFormat: Unknown type!");
 		}
 	}
-	/* Too many arguments for the given format; too few cause crash above */
-	if (!ap)
-		Com_Error(ERR_DROP, "ReadFormat: Too many arguments!");
 }
 
 /**
