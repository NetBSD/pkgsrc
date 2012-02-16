$NetBSD: patch-Xsra_SelFile.c,v 1.1 2012/02/16 18:00:20 hans Exp $

--- Xsra/SelFile.c.orig	2012-01-26 22:11:41.896431520 +0100
+++ Xsra/SelFile.c	2012-01-26 22:14:33.883023396 +0100
@@ -561,19 +561,12 @@ SFopenFile(const char *name, const char 
     SFchdir(SFstartDir);
     if ((fp = fopen(name, mode)) == NULL) {
 	char *buf;
-	if (errno <= sys_nerr) {
-	    buf = XtMalloc(strlen(failed) + strlen(sys_errlist[errno]) + 
-			   strlen(prompt) + 2);
-	    strcpy(buf, failed);
-	    strcat(buf, sys_errlist[errno]);
-	    strcat(buf, "\n");
-	    strcat(buf, prompt);
-	} else {
-	    buf = XtMalloc(strlen(failed) + strlen(prompt) + 2);
-	    strcpy(buf, failed);
-	    strcat(buf, "\n");
-	    strcat(buf, prompt);
-	}
+	buf = XtMalloc(strlen(failed) + strlen(strerror(errno)) + 
+			strlen(prompt) + 2);
+	strcpy(buf, failed);
+	strcat(buf, strerror(errno));
+	strcat(buf, "\n");
+	strcat(buf, prompt);
 	XtSetArg(args[0], XtNlabel, buf);
 	XtSetValues(selFilePrompt, args, 1);
 	XtFree(buf);
