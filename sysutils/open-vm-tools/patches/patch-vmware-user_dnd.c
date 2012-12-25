$NetBSD: patch-vmware-user_dnd.c,v 1.1 2012/12/25 21:02:15 joerg Exp $

--- vmware-user/dnd.c.orig	2012-12-25 19:46:26.000000000 +0000
+++ vmware-user/dnd.c
@@ -943,12 +943,6 @@ DnDRpcInGetNextFileCB(char const **resul
    cpNameSize = CPNameUtil_ConvertToRoot(fileName,
                                          sizeof resultBuffer - (fileNameSize + 1),
                                          resultBuffer + fileNameSize + 1);
-   if (cpNameSize < 0) {
-      Warning("DnDRpcInGetNextFileCB: could not convert to CPName\n");
-      DnDGHCancel(mainWnd);
-      return RpcIn_SetRetVals(result, resultLen,
-                              "error on CPName conversion", FALSE);
-   }
 
    /* Set manually because RpcIn_SetRetVals() assumes no NUL characters */
    *result = resultBuffer;
@@ -1223,14 +1217,6 @@ DnDGtkDataRequestCB(GtkWidget *widget,  
       const size_t origTextLen = textLen;
       Bool freeBegin = FALSE;
 
-      if (len < 0) {
-         Log("DnDGtkDataRequestCB: error getting next component\n");
-         if (text) {
-            free(text);
-         }
-         return;
-      }
-
       /*
        * A URI list will expect the provided path to be escaped.  If we cannot
        * escape the path for some reason we just use the unescaped version and
