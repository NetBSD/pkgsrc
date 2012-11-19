$NetBSD: patch-src_meter_lfapmet.c,v 1.1 2012/11/19 03:03:42 joerg Exp $

--- src/meter/lfapmet.c.orig	2012-11-18 23:39:30.000000000 +0000
+++ src/meter/lfapmet.c
@@ -1115,13 +1115,13 @@ int handleFUN(struct interface_info *pi)
 				ies_len--;
 				for (i=0;i<ies_len;i++) free(ies[i]);
 				if (ies!=NULL) free(ies);	
-				return;
+				return FALSE;
 			}
 			ies[ies_len-1] = malloc(getIELengthIncl(ie));
 			if (ies[ies_len-1]==NULL)
 			{
 				debug("handleFUN(): malloc failed!\n",LFAPMET_DBG_ERRORS);
-				return;
+				return FALSE;
 			}
 			memcpy(ies[ies_len-1],ie,getIELengthIncl(ie));
 			ie = getNextIE(lfap, ie, getLFAPMessageLengthIncl(lfap));
@@ -1132,13 +1132,13 @@ int handleFUN(struct interface_info *pi)
 		{	/* don't forget to free allocated memory ! */
 			for (i=0;i<ies_len;i++) free(ies[i]);
 			if (ies!=NULL) free(ies);
-			return;
+			return FALSE;
 		}
 		if (getIEType(ie) != LFAP_IE_FLOW_ID)
 		{
 			for (i=0;i<ies_len;i++) free(ies[i]);
 			if (ies!=NULL) free(ies);
-			return;
+			return FALSE;
 		}
 	}
 
@@ -1162,7 +1162,7 @@ int handleFUN(struct interface_info *pi)
 				{
 					for (i=0;i<ies_len;i++) free(ies[i]);
 					if (ies!=NULL) free(ies);
-					return;
+					return FALSE;
 				}
 				fs = fi->fs_pp[i];
 				/* see if there's a FAS prefix, set it if so */
