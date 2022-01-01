$NetBSD: patch-sequencer_src_Menu.c,v 1.1 2022/01/01 09:20:41 dholland Exp $

Use standard headers.
Don't use tmpnam().

--- sequencer/src/Menu.c.orig	1997-10-21 21:19:40.000000000 +0000
+++ sequencer/src/Menu.c
@@ -3,9 +3,11 @@
  */
 
 #include <ILClient.h>
-/*#include <sys/types.h>
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <sys/wait.h>
-#include <unistd.h>*/
+/*#include <unistd.h>*/
+#include <limits.h>
 #include "Globals.h"
 
 #include "Types.h"
@@ -251,6 +253,10 @@ END;
 	
 void Midi_NotateCB(Widget w, XtPointer a, XtPointer b)
 {
+	char tempname[PATH_MAX];
+	struct stat buf;
+	int fd;
+
 BEGIN("Midi_NotateCB");
 
 	w = Midi_GetShellWidget(w);
@@ -264,14 +270,25 @@ BEGIN("Midi_NotateCB");
 		END;
 	}
 
-	if (!(MIDItempFileName = XtNewString(tmpnam(NULL))))
+	strcpy(tempname, "/tmp/rosegarden.XXXXXXXX");
+	fd = mkstemp(tempname);
+	if (fd < 0 || (MIDItempFileName = XtNewString(tmpnam(NULL))) == NULL)
 	{
+		close(fd);
 		YQuery(topLevel, "Sorry, I couldn't get a temporary file name.",
 		       1, 0, 0, "Continue", NULL);
 		END;
 	}
 	
 	Midi_SaveFile(MIDItempFileName);
+	if (fstat(fd, &buf) < 0 || buf.st_size == 0)
+	{
+		close(fd);
+		YQuery(topLevel, "Sorry, something went wrong with the temporary file.",
+		       1, 0, 0, "Continue", NULL);
+		END;
+	}
+	close(fd);
 
 	IL_RequestService(ILS_EDIT_SERVICE, Midi_NotateAckCB, MIDItempFileName, strlen(MIDItempFileName) + 1);
 
