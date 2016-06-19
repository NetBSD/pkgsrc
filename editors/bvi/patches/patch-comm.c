$NetBSD: patch-comm.c,v 1.1 2016/06/19 16:55:28 tsutsui Exp $

- use <errno.h> for errno.

--- comm.c.orig	2014-01-29 14:54:53.000000000 +0000
+++ comm.c
@@ -35,6 +35,8 @@
 #include "bvi.h"
 #include "set.h"
 
+#include <errno.h>
+
 #ifdef HAVE_UNISTD_H
 #	include <unistd.h>
 #endif
@@ -84,7 +86,6 @@ PTR		end_addr;
 extern	char	*name;			/* actual filename */
 extern	char	**files;		/* used for "next" and "rewind" */
 extern	int		numfiles, curfile;
-extern	int		errno;
 
 static	char	oldbuf[CMDSZ];		/** for :!! command **/
 
