$NetBSD: patch-archivemount.c,v 1.1 2021/11/30 17:13:14 pho Exp $

Hunk #0:
  On NetBSD there's no <fuse/fuse_lowlevel.h>. The file has to be
  #include'd as <fuse_lowlevel.h>.

Hunk #1:
  Original comment:

  > date: 2007-02-21 09:04:30 +0900;  author: pooka;  state: Exp;  lines: +33 -3;
  > use open(2) instead of mknod(2) to create regular files.  while
  > the latter works on the most current NetBSD, I don't feel like running
  > file systems unnecessarily as the superuser

  But pho@ thinks it doesn't really make any difference, at least on
  NetBSD, because NetBSD librefuse doesn't support non-root mounting
  (via setuid'ed fusermount) and therefore running filesystems as root
  is the only option. Of course filesystems can drop their root
  privilege after calling fuse_mount(), but nobody actually does that.

Hunk #2, #3:
  If fuse_main() is available, use it. There's no need to reimplement
  its functionality, especially since this reimplementation isn't
  API-compatible with NetBSD librefuse.

--- archivemount.c.orig	2020-04-20 11:27:10.000000000 +0000
+++ archivemount.c
@@ -29,7 +29,11 @@
 #include "config.h"
 
 #include <fuse.h>
-#include <fuse/fuse_lowlevel.h>
+#if defined(HAVE_FUSE_FUSE_LOWLEVEL_H)
+#  include <fuse/fuse_lowlevel.h>
+#elif defined(HAVE_FUSE_LOWLEVEL_H)
+#  include <fuse_lowlevel.h>
+#endif
 #include <fuse_opt.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -2224,12 +2228,26 @@ ar_mknod(const char *path, mode_t mode, 
 		return tmp;
 	}
 	/* create temp file */
-	if (mknod(location, mode, rdev) == -1) {
-		log("Could not create temporary file %s: %s",
-			location, strerror(errno));
-		free(location);
-		pthread_mutex_unlock(&lock);
-		return 0 - errno;
+	if (S_ISREG(mode)) {
+		int fd = open(location, O_WRONLY | O_CREAT | O_EXCL, mode);
+
+		if (fd == -1) {
+			log("Could not create temporary file %s: %s",
+				location, strerror(errno));
+			free(location);
+			pthread_mutex_unlock(&lock);
+			return 0 - errno;
+		}
+		close(fd);
+	}
+	else {
+		if (mknod(location, mode, rdev) == -1) {
+			log("Could not create temporary file %s: %s",
+				location, strerror(errno));
+			free(location);
+			pthread_mutex_unlock(&lock);
+			return 0 - errno;
+		}
 	}
 	/* build node */
 	if ((node = init_node()) == NULL) {
@@ -2912,7 +2930,7 @@ main(int argc, char **argv)
 	 */
 	fuse_opt_add_arg(&args, "-s");
 
-#if FUSE_VERSION >= 26
+#if defined(HAVE_FUSE_CHAN_FD)
 	{
 		struct fuse *fuse;
 		struct fuse_chan *ch;
@@ -2974,13 +2992,13 @@ main(int argc, char **argv)
 		fuse_destroy(fuse);
 		free(mountpoint);
 	}
-#else
+#else /* defined(HAVE_FUSE_CHAN_FD) */
 	{
 		/* now do the real mount */
 		int fuse_ret;
 		fuse_ret = fuse_main(args.argc, args.argv, &ar_oper, NULL);
 	}
-#endif
+#endif /* defined(HAVE_FUSE_CHAN_FD) */
 
 	/* go back to saved dir */
 	{
