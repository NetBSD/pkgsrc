$NetBSD: patch-cone_myserverremoteconfig.C,v 1.1 2020/03/22 21:24:56 joerg Exp $

--- cone/myserverremoteconfig.C.orig	2020-03-22 20:25:04.977804903 +0000
+++ cone/myserverremoteconfig.C
@@ -142,7 +142,7 @@ mail::account *myServer::remoteConfig::l
 			if (a)
 				delete a;
 			errmsg=callback.msg;
-			return false;
+			return NULL;
 		}
 		break;
 	}
