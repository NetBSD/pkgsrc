$NetBSD: patch-vmware-user_copyPaste.c,v 1.1 2012/12/25 21:02:15 joerg Exp $

--- vmware-user/copyPaste.c.orig	2012-12-25 19:45:44.000000000 +0000
+++ vmware-user/copyPaste.c
@@ -655,14 +655,6 @@ CopyPasteSelectionGetCB(GtkWidget       
       const size_t origTextLen = textLen;
       Bool freeBegin = FALSE;
 
-      if (len < 0) {
-         Debug("CopyPasteSelectionGetCB: error getting next component\n");
-         if (text) {
-            free(text);
-         }
-         return;
-      }
-
       /*
        * A URI list will expect the provided path to be escaped.  If we cannot
        * escape the path for some reason we just use the unescaped version and
@@ -1761,11 +1753,6 @@ CopyPasteRpcInGHGetNextFileCB(char const
    cpNameSize = CPNameUtil_ConvertToRoot(fileName,
                                          sizeof resultBuffer - (fileNameSize + 1),
                                          resultBuffer + fileNameSize + 1);
-   if (cpNameSize < 0) {
-      Warning("CopyPasteRpcInGHGetNextFileCB: could not convert to CPName\n");
-      return RpcIn_SetRetVals(result, resultLen,
-                              "error on CPName conversion", FALSE);
-   }
 
    /* Set manually because RpcIn_SetRetVals() assumes no NUL characters */
    *result = resultBuffer;
