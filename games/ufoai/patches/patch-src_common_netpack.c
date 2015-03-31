$NetBSD: patch-src_common_netpack.c,v 1.1 2015/03/31 15:40:03 joerg Exp $

--- src/common/netpack.c.orig	2015-03-26 15:39:22.000000000 +0000
+++ src/common/netpack.c
@@ -189,9 +189,6 @@ void NET_V_WriteFormat (struct dbuffer *
 			Com_Error(ERR_DROP, "WriteFormat: Unknown type!");
 		}
 	}
-	/* Too many arguments for the given format; too few cause crash above */
-	if (!ap)
-		Com_Error(ERR_DROP, "WriteFormat: Too many arguments!");
 }
 
 /**
@@ -470,9 +467,6 @@ void NET_V_ReadFormat (struct dbuffer *b
 			Com_Error(ERR_DROP, "ReadFormat: Unknown type!");
 		}
 	}
-	/* Too many arguments for the given format; too few cause crash above */
-	if (!ap)
-		Com_Error(ERR_DROP, "ReadFormat: Too many arguments!");
 }
 
 /**
