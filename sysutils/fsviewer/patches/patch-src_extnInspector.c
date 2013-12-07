$NetBSD: patch-src_extnInspector.c,v 1.1 2013/12/07 18:24:59 dholland Exp $

Fix build with current windowmaker.

--- src/extnInspector.c~	2002-12-14 21:35:58.000000000 +0000
+++ src/extnInspector.c
@@ -229,7 +229,7 @@ storeData(_Panel *panel)
 
     if(numRows > 0)
 	WMWritePropListToFile(filesDB,
-	  wdefaultspathfordomain("FSViewer"), True);
+	  wdefaultspathfordomain("FSViewer"));
 
    if(extn)
 	free(extn);
