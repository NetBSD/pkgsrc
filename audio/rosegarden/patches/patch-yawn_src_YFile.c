$NetBSD: patch-yawn_src_YFile.c,v 1.1 2022/01/01 09:20:41 dholland Exp $

Silence compiler warnings.

--- yawn/src/YFile.c~	1996-12-22 21:53:24.000000000 +0000
+++ yawn/src/YFile.c
@@ -740,7 +740,7 @@ Boolean FileSetFileNameList(void)
 
   } else {
 
-    XawListChange(fileList, filecall, filecount, mwd > 300 ? mwd+6 : 300, True);
+    XawListChange(fileList, (const char **)filecall, filecount, mwd > 300 ? mwd+6 : 300, True);
   }
 
   XawListUnhighlight(fileList);
@@ -1256,7 +1256,7 @@ void FileName(Widget w, XtPointer a, XtP
 
 void FileFilter(Widget w, XtPointer a, XtPointer b)
 {
-  int answer = (int)b;
+  int answer = (int)(intptr_t)b;
 
   FilterSuffix = fileFilterOptions[0] ? answer == 0 : False;
   GlobDots     = fileFilterOptions[0] ? answer >  1 : answer > 0;
