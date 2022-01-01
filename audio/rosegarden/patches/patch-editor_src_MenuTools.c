$NetBSD: patch-editor_src_MenuTools.c,v 1.1 2022/01/01 09:20:41 dholland Exp $

Use standard headers.
Don't use tmpnam().
Don't use sprintf().
Use ctype functions correctly.

--- editor/src/MenuTools.c.orig	1997-09-22 20:20:07.000000000 +0000
+++ editor/src/MenuTools.c
@@ -13,6 +13,8 @@
 #include "Menu.h"
 #include "StaveEdit.h"
 
+#include <sys/stat.h>
+#include <ctype.h>		/* for isdigit */
 #include <unistd.h>		/* for unlink */
 
 #include <Yawn.h>
@@ -28,7 +30,10 @@ void SequenceAcknowledgeCallback(IL_Retu
 {
   Begin("SequenceCompleteCallback");
 
-  if (filename) (void)unlink(filename);	/* can't do anything about failure */
+  if (filename) {
+    (void)unlink(filename);	/* can't do anything about failure */
+    XtFree(filename);
+  }
 
   StaveBusy(False);
 
@@ -68,12 +73,17 @@ void SequenceAcknowledgeCallback(IL_Retu
 
 void FileMenuSequence(Widget w, XtPointer a, XtPointer b)
 {
+  char namebuf[PATH_MAX];
+  struct stat buf;
+  int fd;
   int len;
   String name;
   String sname;
   Begin("FileMenuSequence");
 
-  if (!(filename = tmpnam(NULL))) {
+  strcpy(namebuf, "/tmp/rosegarden.XXXXXXXX");
+  fd = mkstemp(namebuf);
+  if (fd < 0 || (filename = XtNewString(namebuf)) == NULL) {
     IssueMenuComplaint("Sorry, I couldn't get a temporary file name.");
     End;
   }
@@ -83,17 +93,24 @@ void FileMenuSequence(Widget w, XtPointe
   name = (String)XtMalloc(len + 25);
 
   if (len > 13 && !strcmp(sname + len - 12, " (temporary)")) {
-    sprintf(name, "%s", sname);
+    snprintf(name, len + 25, "%s", sname);
   } else {
-    sprintf(name, "%s (temporary)", sname);
+    snprintf(name, len + 25, "%s (temporary)", sname);
   }
 
   if (MidiWriteStave(stave, filename, name) == Failed) {
     XtFree(name);
+    close(fd);
     End;
   }
 
   XtFree(name);
+  if (fstat(fd, &buf) < 0 || buf.st_size == 0) {
+    IssueMenuComplaint("Sorry, something went wrong with the temporary file.");
+    close(fd);
+    End;
+  }
+  close(fd);
 
   StaveBusy(True);
   IL_RequestService(ILS_SEQUENCE_SERVICE, SequenceAcknowledgeCallback,
@@ -271,7 +288,7 @@ void FileMenuFollowILCallback(String chu
 
   IL_AcknowledgeRequest(ILS_FOLLOW_SERVICE, IL_SERVICE_OK);
 
-  if (!isdigit(chunk[0]) && chunk[0] != '-') {
+  if (!isdigit((unsigned char)chunk[0]) && chunk[0] != '-') {
 
     if (!strcmp(chunk, ILS_FOLLOW_UNLOCK)) {
 
