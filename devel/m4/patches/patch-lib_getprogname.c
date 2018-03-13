$NetBSD: patch-lib_getprogname.c,v 1.1 2018/03/13 20:26:43 jmcneill Exp $

--- lib/getprogname.c.orig	Tue Mar 13 15:45:15 AST 2018
+++ lib/getprogname.c	Tue Mar 13 15:49:41 AST 2018
@@ -43,6 +43,14 @@
 # include <string.h>
 #endif
 
+#ifdef __sgi
+# include <string.h>
+# include <unistd.h>
+# include <stdio.h>
+# include <fcntl.h>
+# include <sys/procfs.h>
+#endif
+
 #include "dirname.h"
 
 #ifndef HAVE_GETPROGNAME             /* not Mac OS X, FreeBSD, NetBSD, OpenBSD >= 5.4, Cygwin */
@@ -143,6 +151,32 @@
       free (buf.ps_pathptr);
     }
   return p;
+# elif defined __sgi
+  char filename[50];
+  int fd;
+
+  sprintf (filename, "/proc/pinfo/%d", (int) getpid ());
+  fd = open (filename, O_RDONLY);
+  if (0 <= fd)
+    {
+      prpsinfo_t buf;
+      int ioctl_ok = 0 <= ioctl (fd, PIOCPSINFO, &buf);
+      close (fd);
+      if (ioctl_ok)
+	{
+	  char *name = buf.pr_fname;
+	  char *namesize = sizeof buf.pr_fname;
+	  char *namenul = memchr (name, '\0', namesize);
+	  size_t namelen = namenul ? namenul - name : namesize;
+	  char *namecopy = malloc (namelen + 1);
+	  if (namecopy)
+	    {
+	      namecopy[namelen] = 0;
+	      return memcpy (namecopy, name, namelen);
+	    }
+	}
+    }
+  return NULL;
 # else
 #  error "getprogname module not ported to this OS"
 # endif
