$NetBSD: patch-client-src_getfsent.c,v 1.1 2016/02/29 05:50:40 mlelstv Exp $

Support looking up devices by name.

--- client-src/getfsent.c.orig	2012-02-21 12:36:41.000000000 +0100
+++ client-src/getfsent.c	2016-02-28 09:39:42.565217334 +0100
@@ -41,6 +41,12 @@
 
 static char *dev2rdev(char *);
 
+#if (defined __NetBSD__ && __NetBSD_Version__ >= 699000000)
+/* #include <util.h> */
+const char     *getdiskrawname(char *, size_t, const char *);
+const char     *getfsspecname(char *, size_t, const char *);
+#endif
+
 /*
  * You are in a twisty maze of passages, all alike.
  * Geesh.
@@ -74,10 +80,20 @@
     struct fstab *sys_fsent = getfsent();
     static char *xfsname = NULL, *xmntdir = NULL;
     static char *xfstype = NULL, *xmntopts = NULL;
+#if defined __NetBSD__ && __NetBSD_Version__ >= 699000000
+    char buf[MAXPATHLEN];
+    const char *spec;
+#endif
 
     if(!sys_fsent)
 	return 0;
+#if defined __NetBSD__ && __NetBSD_Version__ >= 699000000
+    spec = getfsspecname(buf, sizeof(buf), sys_fsent->fs_spec);
+    if (spec == NULL) spec = sys_fsent->fs_spec;
+    fsent->fsname  = xfsname  = newstralloc(xfsname, spec);
+#else
     fsent->fsname  = xfsname  = newstralloc(xfsname,  sys_fsent->fs_spec);
+#endif
     fsent->mntdir  = xmntdir  = newstralloc(xmntdir,  sys_fsent->fs_file);
     fsent->freq    = sys_fsent->fs_freq;
     fsent->passno  = sys_fsent->fs_passno;
@@ -429,10 +445,15 @@
 dev2rdev(
     char *	name)
 {
-  char *fname = NULL;
   struct stat st;
+#if (defined __NetBSD__ && __NetBSD_Version__ >= 699000000)
+  char buf[MAXPATHLEN];
+  const char *raw;
+#else
+  char *fname = NULL;
   char *s;
   int ch;
+#endif
 
   if(stat(name, &st) == 0 && !S_ISBLK(st.st_mode)) {
     /*
@@ -441,6 +462,10 @@
     return stralloc(name);
   }
 
+#if (defined __NetBSD__ && __NetBSD_Version__ >= 699000000)
+  raw = getdiskrawname(buf, sizeof(buf), name);
+  if (raw) return stralloc(raw);
+#else /* ! (defined __NetBSD__ && __NetBSD_Version__ >= 699000000) */
   s = name;
   ch = *s++;
 
@@ -464,6 +489,7 @@
     ch = *s++;
   }
   amfree(fname);
+#endif
   return stralloc(name);			/* no match */
 }
 
