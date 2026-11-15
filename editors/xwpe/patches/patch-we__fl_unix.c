$NetBSD: patch-we__fl_unix.c,v 1.1 2026/11/15 13:14:45 vins Exp $

Adjust man path for pkgsrc.

--- we_fl_unix.c.orig
+++ we_fl_unix.c
@@ -3661,7 +3661,7 @@ struct dirfile *e_make_funct(char *man)
  }
  if ((!manpath) || (manpath[0] == '\0'))
  {
-  manpath = strdup("/usr/man:/usr/share/man:/usr/X11R6/man:/usr/local/man");
+  manpath = strdup("/usr/share/man:/usr/X11R7/man:/usr/local/man:@PREFIX@/@PKGMANDIR@");
  }
  /* Allocate the maximum possible rather than continually realloc. */
  sustr = malloc(strlen(manpath) + 10);
