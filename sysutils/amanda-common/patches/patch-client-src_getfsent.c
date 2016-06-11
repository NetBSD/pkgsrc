$NetBSD: patch-client-src_getfsent.c,v 1.2 2016/06/11 21:07:28 dholland Exp $

Support looking up devices by name.

--- client-src/getfsent.c.orig	2012-02-21 11:36:41.000000000 +0000
+++ client-src/getfsent.c
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
@@ -74,10 +80,20 @@ get_fstab_nextentry(
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
@@ -429,10 +445,15 @@ static char *
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
@@ -441,6 +462,10 @@ dev2rdev(
     return stralloc(name);
   }
 
+#if (defined __NetBSD__ && __NetBSD_Version__ >= 699000000)
+  raw = getdiskrawname(buf, sizeof(buf), name);
+  if (raw) return stralloc(raw);
+#else /* ! (defined __NetBSD__ && __NetBSD_Version__ >= 699000000) */
   s = name;
   ch = *s++;
 
@@ -464,6 +489,7 @@ dev2rdev(
     ch = *s++;
   }
   amfree(fname);
+#endif
   return stralloc(name);			/* no match */
 }
 
@@ -477,6 +503,8 @@ samefile(
 {
   int i;
   for(i = 0; i < 3; ++i) {
+    if (stats[i].st_dev == (dev_t)-1)
+      continue;
     if (stats[i].st_dev == estat->st_dev &&
 	stats[i].st_ino == estat->st_ino)
       return 1;
