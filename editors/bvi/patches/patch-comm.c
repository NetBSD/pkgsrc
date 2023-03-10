$NetBSD: patch-comm.c,v 1.2 2023/03/10 21:56:18 ryoon Exp $

- use <errno.h> for errno.

--- comm.c.orig	2023-03-06 16:40:20.000000000 +0000
+++ comm.c
@@ -37,6 +37,8 @@
 #include "bvi.h"
 #include "set.h"
 
+#include <errno.h>
+
 #ifdef HAVE_UNISTD_H
 #	include <unistd.h>
 #endif
@@ -86,7 +88,6 @@ PTR		end_addr;
 extern	char	*name;			/* actual filename */
 extern	char	**files;		/* used for "next" and "rewind" */
 extern	int		numfiles, curfile;
-extern	int		errno;
 
 static	char	oldbuf[CMDSZ + 3];		/** for :!! command **/
 
