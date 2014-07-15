$NetBSD: patch-scandir.c,v 1.1 2014/07/15 14:48:34 ryoon Exp $

--- scandir.c.orig	2014-07-14 12:36:57.000000000 +0000
+++ scandir.c
@@ -0,0 +1,137 @@
+/*                               -*- Mode: C -*- 
+ * Basename: scandir.c 
+ * Revision: 1.3.1.5.1.3 
+ * Last Modified By: Ulrich Pfeifer
+ * Last Modified On: Tue May 13 13:15:16 1997
+ * Language        : C
+ * Update Count    : 2
+ * Status          : Unknown, Use with caution!
+ * 
+ * (C) Copyright 1997, Universität Dortmund, all rights reserved.
+ * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
+ */
+
+/*
+Title: COPYRIGHT freeWAIS-0.2
+Author: Jane Smith 
+Copyright: Copyright 1993 CNIDR 
+Last update: 10.01.93 
+Abstract: This file contains the copyright statement for freeWAIS 0.2
+
+Copyright Statement for freeWAIS 0.2 and subsquent freeWAIS
+releases:
+
+Copyright (c) MCNC, Clearinghouse for Networked Information Discovery
+and Retrieval, 1993. 
+
+Permission to use, copy, modify, distribute, and sell this software
+and its documentation, in whole or in part, for any purpose is hereby
+granted without fee, provided that
+
+1. The above copyright notice and this permission notice appear in all
+copies of the software and related documentation. Notices of copyright
+and/or attribution which appear at the beginning of any file included
+in this distribution must remain intact.
+
+2. Users of this software agree to make their best efforts (a) to
+return to MCNC any improvements or extensions that they make, so that
+these may be included in future releases; and (b) to inform MCNC/CNIDR
+of noteworthy uses of this software.
+
+3. The names of MCNC and Clearinghouse for Networked Information
+Discovery and Retrieval may not be used in any advertising or publicity
+relating to the software without the specific, prior written permission
+of MCNC/CNIDR. 
+
+THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,
+EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY
+WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
+
+IN NO EVENT SHALL MCNC/CNIDR BE LIABLE FOR ANY SPECIAL, INCIDENTAL,
+INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER
+RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER OR NOT ADVISED OF
+THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF LIABILITY, ARISING OUT
+OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
+*/
+
+/*
+ *  SCANDIR
+ *  Scan a directory, collecting all (selected) items into a an array.
+ */
+
+#include <stdio.h>
+#include <dirent.h>
+#include <stdlib.h>
+#include <string.h>
+
+#ifdef DIRNAMLEN
+#define NLENGTH(dirent)	((dirent)->d_namlen)
+#else /* not DIRNAMLEN */
+#define NLENGTH(dirent)	(strlen((dirent)->d_name))
+#endif /* not DIRNAMLEN */
+
+/* Initial guess at directory size. */
+#define INITIAL_SIZE	20
+
+int
+scandir(name, list, selector, sorter)
+    char		  *name;
+    dirent_t		  ***list;
+    int			 (*selector)();
+    int			 (*sorter)();
+{
+    register dirent_t	  **names;
+    register dirent_t	  *entp;
+    register DIR	  *dirp;
+    register int	   i;
+    register int	   size;
+
+    /* Get initial list space and open directory. */
+    size = INITIAL_SIZE;
+    names = (dirent_t **)malloc(size * sizeof names[0]);
+    if (names == NULL)
+	return -1;
+    dirp = opendir(name);
+    if (dirp == NULL)
+	return -1;
+
+    /* Read entries in the directory. */
+    for (i = 0; entp = readdir(dirp); )
+	if (selector == NULL || (*selector)(entp)) {
+	    /* User wants them all, or he wants this one. */
+	    if (++i >= size) {
+		size <<= 1;
+		names = (dirent_t **)
+		    realloc((char *)names, size * sizeof names[0]);
+		if (names == NULL) {
+		    closedir(dirp);
+		    return -1;
+		}
+	    }
+
+	    /* Copy the entry. */
+	    names[i - 1] = (dirent_t *)malloc(sizeof(dirent_t) 
+					        + NLENGTH(entp)+1);
+	    if (names[i - 1] == NULL) {
+		closedir(dirp);
+		return -1;
+	    }
+	    names[i - 1]->d_ino = entp->d_ino;
+	    names[i - 1]->d_reclen = entp->d_reclen;
+#ifdef DIRNAMLEN
+	    names[i - 1]->d_namlen = entp->d_namlen;
+#endif
+	    (void)strcpy(names[i - 1]->d_name, entp->d_name);
+	}
+
+    /* Close things off. */
+    names[i] = NULL;
+    *list = names;
+    closedir(dirp);
+
+    /* Sort? */
+    if (i && sorter)
+	qsort((char *)names, i, sizeof names[0], sorter);
+
+    return i;
+}
