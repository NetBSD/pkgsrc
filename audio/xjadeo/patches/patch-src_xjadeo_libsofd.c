$NetBSD: patch-src_xjadeo_libsofd.c,v 1.1 2016/06/19 09:16:15 kamil Exp $

Add NetBSD support.

Backport getmntent() from sysutils/fam.

--- src/xjadeo/libsofd.c.orig	2015-11-25 14:17:19.000000000 +0000
+++ src/xjadeo/libsofd.c
@@ -334,8 +334,167 @@ const char *x_fib_recent_file(const char
 
 #ifdef XFIB
 #if (defined HAVE_LIBXV || defined HAVE_IMLIB2 || (defined HAVE_GL && !defined PLATFORM_WINDOWS && !defined PLATFORM_OSX))
+#if defined PLATFORM_LINUX
 #include <mntent.h>
+#endif
 #include <dirent.h>
+#if defined PLATFORM_NETBSD
+#include <sys/types.h>
+#include <sys/statvfs.h>
+
+#include <stdio.h>
+
+#define MOUNTED "dummy"
+
+#define MNTTYPE_NFS "nfs"
+
+struct mntent {
+        char *mnt_fsname;
+        char *mnt_dir;
+        char *mnt_type;
+        char *mnt_opts;
+        int mnt_freq;
+        int mnt_passno;
+};
+
+#define setmntent(x,y) ((FILE *)0x1)
+struct mntent *getmntent __P ((FILE *fp));
+char *hasmntopt __P ((const struct mntent *mnt, const char *option));
+#define endmntent(x) ((int)1)
+
+static int pos = -1;
+static int mntsize = -1;
+static struct mntent _mntent;
+
+char *
+hasmntopt (const struct mntent *mnt, const char *option)
+{
+        int found;
+        char *opt, *optbuf;
+
+        optbuf = strdup(mnt->mnt_opts);
+        found = 0;
+        for (opt = optbuf; (opt = strtok(opt, " ")) != NULL; opt = NULL) {
+                if (!strcasecmp(opt, option)) {
+			opt = opt - optbuf + mnt->mnt_opts;
+			free (optbuf);
+			return (opt);
+		}
+        }
+	free (optbuf);
+        return (NULL);
+}
+
+static char *
+catopt (char *s0, const char *s1)
+{
+        size_t i;
+        char *cp;
+
+        if (s1 == NULL || *s1 == '\0')
+                return s0;
+        if (s0 && *s0) {
+                i = strlen(s0) + strlen(s1) + 1 + 1;
+                if ((cp = (char *)malloc(i)) == NULL)
+			return (NULL);
+                (void)snprintf(cp, i, "%s %s", s0, s1);
+        } else
+                cp = strdup(s1);
+
+        if (s0)
+                free(s0);
+        return (cp);
+}
+
+static char *
+flags2opts (int flags)
+{
+        char *res;
+        res = NULL;
+        res = catopt(res, (flags & MNT_RDONLY) ? "ro" : "rw");
+        if (flags & MNT_SYNCHRONOUS)    res = catopt(res, "sync");
+        if (flags & MNT_NOEXEC)         res = catopt(res, "noexec");
+        if (flags & MNT_NOSUID)         res = catopt(res, "nosuid");
+#ifdef MNT_NODEV
+        if (flags & MNT_NODEV)          res = catopt(res, "nodev");
+#endif
+#ifdef MNT_UNION
+        if (flags & MNT_UNION)          res = catopt(res, "union");
+#endif
+        if (flags & MNT_ASYNC)          res = catopt(res, "async");
+#ifdef MNT_NOATIME
+        if (flags & MNT_NOATIME)        res = catopt(res, "noatime");
+#endif
+#ifdef MNT_NOCLUSTERR
+        if (flags & MNT_NOCLUSTERR)     res = catopt(res, "noclusterr");
+#endif
+#ifdef MNT_NOCLUSTERW
+        if (flags & MNT_NOCLUSTERW)     res = catopt(res, "noclusterw");
+#endif
+#ifdef MNT_NOSYMFOLLOW
+        if (flags & MNT_NOSYMFOLLOW)    res = catopt(res, "nosymfollow");
+#endif
+#ifdef MNT_SUIDDIR
+        if (flags & MNT_SUIDDIR)        res = catopt(res, "suiddir");
+#endif
+#ifdef MNT_NOCOREDUMP
+        if (flags & MNT_NOCOREDUMP)	res = catopt(res, "nocoredump");
+#endif
+#ifdef MNT_IGNORE
+        if (flags & MNT_IGNORE)		res = catopt(res, "hidden");
+#endif
+#ifdef MNT_SYMPERM
+        if (flags & MNT_SYMPERM)	res = catopt(res, "symperm");
+#endif
+#ifdef MNT_NODEVMTIME
+        if (flags & MNT_NODEVMTIME)	res = catopt(res, "nodevmtime");
+#endif
+#ifdef MNT_SOFTDEP
+        if (flags & MNT_SOFTDEP)	res = catopt(res, "softdep");
+#endif
+
+        return res;
+}
+
+static struct mntent *
+statfs_to_mntent (struct statvfs *mntbuf)
+{
+	static char opts_buf[40], *tmp;
+	
+	_mntent.mnt_fsname = mntbuf->f_mntfromname;
+	_mntent.mnt_dir = mntbuf->f_mntonname;
+	_mntent.mnt_type = mntbuf->f_fstypename;
+	tmp = flags2opts (mntbuf->f_flag);
+
+	if (tmp) {
+		opts_buf[sizeof(opts_buf)-1] = '\0';
+		strncpy (opts_buf, tmp, sizeof(opts_buf)-1);
+		free (tmp);
+	} else {
+		*opts_buf = '\0';
+	}
+	_mntent.mnt_opts = opts_buf;	
+	_mntent.mnt_freq = _mntent.mnt_passno = 0;
+	return (&_mntent);
+}
+
+struct mntent *
+getmntent (FILE *fp)
+{
+	static struct statvfs *mntbuf;
+
+	if (pos == -1 || mntsize == -1)
+		mntsize = getmntinfo (&mntbuf, MNT_NOWAIT);
+
+	++pos;
+	if (pos == mntsize) {
+		pos = mntsize = -1;
+		return (NULL);
+	}
+
+	return (statfs_to_mntent (&mntbuf[pos]));
+}
+#endif
 
 #include <X11/Xlib.h>
 #include <X11/Xatom.h>
