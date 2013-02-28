$NetBSD: patch-lib.c,v 1.1 2013/02/28 19:21:04 is Exp $

--- lib.c.orig	2013-02-28 15:59:08.000000000 +0000
+++ lib.c
@@ -548,7 +548,6 @@ static int mutt_mkwrapdir (const char *p
   const char *basename;
   char parent[_POSIX_PATH_MAX];
   char *p;
-  int rv;
 
   strfcpy (parent, NONULL (path), sizeof (parent));
   
@@ -563,14 +562,8 @@ static int mutt_mkwrapdir (const char *p
     basename = path;
   }
 
-  do 
-  {
-    snprintf (newdir, ndlen, "%s/%s", parent, ".muttXXXXXX");
-    mktemp (newdir);
-  } 
-  while ((rv = mkdir (newdir, 0700)) == -1 && errno == EEXIST);
-  
-  if (rv == -1)
+  snprintf (newdir, ndlen, "%s/%s", parent, ".muttXXXXXX");
+  if (mkdtemp (newdir) == NULL)
     return -1;
   
   snprintf (newfile, nflen, "%s/%s", newdir, NONULL(basename));
