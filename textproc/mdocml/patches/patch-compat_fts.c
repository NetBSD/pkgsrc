$NetBSD: patch-compat_fts.c,v 1.4 2015/03/26 14:16:12 sevan Exp $

"We always use FTS_NOCHDIR, so delete the directory changing code.
This not only simplifies matters, but also helps operating systems
lacking dirfd(3), for example Solaris 10."

--- compat_fts.c.orig	2015-03-26 04:03:30.000000000 +0000
+++ compat_fts.c
@@ -60,7 +60,6 @@ static size_t	 fts_maxarglen(char * cons
 static void	 fts_padjust(FTS *, FTSENT *);
 static int	 fts_palloc(FTS *, size_t);
 static unsigned short	 fts_stat(FTS *, FTSENT *);
-static int	 fts_safe_changedir(FTS *, FTSENT *, int, const char *);
 
 #define	ISDOT(a)	(a[0] == '.' && (!a[1] || (a[1] == '.' && !a[2])))
 #ifndef	O_DIRECTORY
@@ -74,8 +73,6 @@ static int	 fts_safe_changedir(FTS *, FT
 #define	ISSET(opt)	(sp->fts_options & (opt))
 #define	SET(opt)	(sp->fts_options |= (opt))
 
-#define	FCHDIR(sp, fd)	(!ISSET(FTS_NOCHDIR) && fchdir(fd))
-
 FTS *
 fts_open(char * const *argv, int options, void *dummy)
 {
@@ -146,17 +143,6 @@ fts_open(char * const *argv, int options
 	sp->fts_cur->fts_link = root;
 	sp->fts_cur->fts_info = FTS_INIT;
 
-	/*
-	 * If using chdir(2), grab a file descriptor pointing to dot to ensure
-	 * that we can get back here; this could be avoided for some paths,
-	 * but almost certainly not worth the effort.  Slashes, symbolic links,
-	 * and ".." are all fairly nasty problems.  Note, if we can't get the
-	 * descriptor we run anyway, just more slowly.
-	 */
-	if (!ISSET(FTS_NOCHDIR) &&
-	    (sp->fts_rfd = open(".", O_RDONLY | O_CLOEXEC)) < 0)
-		SET(FTS_NOCHDIR);
-
 	if (nitems == 0)
 		free(parent);
 
@@ -213,25 +199,13 @@ fts_close(FTS *sp)
 		free(p);
 	}
 
-	/* Stash the original directory fd if needed. */
-	rfd = ISSET(FTS_NOCHDIR) ? -1 : sp->fts_rfd;
-
 	/* Free up child linked list, sort array, path buffer, stream ptr.*/
 	if (sp->fts_child)
 		fts_lfree(sp->fts_child);
 	free(sp->fts_path);
 	free(sp);
 
-	/* Return to original directory, checking for error. */
-	if (rfd != -1) {
-		int saved_errno;
-		error = fchdir(rfd);
-		saved_errno = errno;
-		(void)close(rfd);
-		errno = saved_errno;
-	}
-
-	return (error);
+	return (0);
 }
 
 /*
@@ -274,25 +248,11 @@ fts_read(FTS *sp)
 		}
 
 		/*
-		 * Cd to the subdirectory.
-		 *
-		 * If have already read and now fail to chdir, whack the list
-		 * to make the names come out right, and set the parent errno
-		 * so the application will eventually get an error condition.
-		 * Set the FTS_DONTCHDIR flag so that when we logically change
-		 * directories back to the parent we don't do a chdir.
-		 *
 		 * If haven't read do so.  If the read fails, fts_build sets
 		 * FTS_STOP or the fts_info field of the node.
 		 */
 		if (sp->fts_child) {
-			if (fts_safe_changedir(sp, p, -1, p->fts_accpath)) {
-				p->fts_errno = errno;
-				p->fts_flags |= FTS_DONTCHDIR;
-				for (p = sp->fts_child; p; p = p->fts_link)
-					p->fts_accpath =
-					    p->fts_parent->fts_accpath;
-			}
+			/* nothing */
 		} else if ((sp->fts_child = fts_build(sp)) == NULL) {
 			if (ISSET(FTS_STOP))
 				return (NULL);
@@ -352,23 +312,6 @@ name:		t = sp->fts_path + NAPPEND(p->fts
 	/* NUL terminate the pathname. */
 	sp->fts_path[p->fts_pathlen] = '\0';
 
-	/*
-	 * Return to the parent directory.  If at a root node or came through
-	 * a symlink, go back through the file descriptor.  Otherwise, cd up
-	 * one directory.
-	 */
-	if (p->fts_level == FTS_ROOTLEVEL) {
-		if (FCHDIR(sp, sp->fts_rfd)) {
-			SET(FTS_STOP);
-			sp->fts_cur = p;
-			return (NULL);
-		}
-	} else if (!(p->fts_flags & FTS_DONTCHDIR) &&
-	    fts_safe_changedir(sp, p->fts_parent, -1, "..")) {
-		SET(FTS_STOP);
-		sp->fts_cur = p;
-		return (NULL);
-	}
 	p->fts_info = p->fts_errno ? FTS_ERR : FTS_DP;
 	return (sp->fts_cur = p);
 }
@@ -432,32 +375,6 @@ fts_build(FTS *sp)
 	}
 
 	/*
-	 * If we're going to need to stat anything or we want to descend
-	 * and stay in the directory, chdir.  If this fails we keep going,
-	 * but set a flag so we don't chdir after the post-order visit.
-	 * We won't be able to stat anything, but we can still return the
-	 * names themselves.  Note, that since fts_read won't be able to
-	 * chdir into the directory, it will have to return different path
-	 * names than before, i.e. "a/b" instead of "b".  Since the node
-	 * has already been visited in pre-order, have to wait until the
-	 * post-order visit to return the error.  There is a special case
-	 * here, if there was nothing to stat then it's not an error to
-	 * not be able to stat.  This is all fairly nasty.  If a program
-	 * needed sorted entries or stat information, they had better be
-	 * checking FTS_NS on the returned nodes.
-	 */
-	cderrno = 0;
-	if (fts_safe_changedir(sp, cur, dirfd(dirp), NULL)) {
-		cur->fts_errno = errno;
-		cur->fts_flags |= FTS_DONTCHDIR;
-		descend = 0;
-		cderrno = errno;
-		(void)closedir(dirp);
-		dirp = NULL;
-	} else
-		descend = 1;
-
-	/*
 	 * Figure out the max file name length that can be stored in the
 	 * current path -- the inner loop allocates more path as necessary.
 	 * We really wouldn't have to do the maxlen calculations here, we
@@ -468,10 +385,8 @@ fts_build(FTS *sp)
 	 * each new name into the path.
 	 */
 	len = NAPPEND(cur);
-	if (ISSET(FTS_NOCHDIR)) {
-		cp = sp->fts_path + len;
-		*cp++ = '/';
-	}
+	cp = sp->fts_path + len;
+	*cp++ = '/';
 	len++;
 	maxlen = sp->fts_pathlen - len;
 
@@ -518,8 +433,7 @@ mem1:				saved_errno = errno;
 			/* Did realloc() change the pointer? */
 			if (oldaddr != sp->fts_path) {
 				doadjust = 1;
-				if (ISSET(FTS_NOCHDIR))
-					cp = sp->fts_path + len;
+				cp = sp->fts_path + len;
 			}
 			maxlen = sp->fts_pathlen - len;
 		}
@@ -542,20 +456,11 @@ mem1:				saved_errno = errno;
 			return (NULL);
 		}
 
-		if (cderrno) {
-			p->fts_info = FTS_NS;
-			p->fts_errno = cderrno;
-			p->fts_accpath = cur->fts_accpath;
-		} else {
-			/* Build a file name for fts_stat to stat. */
-			if (ISSET(FTS_NOCHDIR)) {
-				p->fts_accpath = p->fts_path;
-				memmove(cp, p->fts_name, p->fts_namelen + 1);
-			} else
-				p->fts_accpath = p->fts_name;
-			/* Stat it. */
-			p->fts_info = fts_stat(sp, p);
-		}
+		/* Build a file name for fts_stat to stat. */
+		p->fts_accpath = p->fts_path;
+		memmove(cp, p->fts_name, p->fts_namelen + 1);
+		/* Stat it. */
+		p->fts_info = fts_stat(sp, p);
 
 		/* We walk in directory order so "ls -f" doesn't get upset. */
 		p->fts_link = NULL;
@@ -581,26 +486,9 @@ mem1:				saved_errno = errno;
 	 * If not changing directories, reset the path back to original
 	 * state.
 	 */
-	if (ISSET(FTS_NOCHDIR)) {
-		if (len == sp->fts_pathlen || nitems == 0)
-			--cp;
-		*cp = '\0';
-	}
-
-	/*
-	 * If descended after called from fts_children or after called from
-	 * fts_read and nothing found, get back.  At the root level we use
-	 * the saved fd; if one of fts_open()'s arguments is a relative path
-	 * to an empty directory, we wind up here with no other way back.  If
-	 * can't get back, we're done.
-	 */
-	if (descend && !nitems &&
-	    (cur->fts_level == FTS_ROOTLEVEL ? FCHDIR(sp, sp->fts_rfd) :
-	    fts_safe_changedir(sp, cur->fts_parent, -1, ".."))) {
-		cur->fts_info = FTS_ERR;
-		SET(FTS_STOP);
-		return (NULL);
-	}
+	if (len == sp->fts_pathlen || nitems == 0)
+		--cp;
+	*cp = '\0';
 
 	/* If didn't find anything, return NULL. */
 	if (!nitems) {
@@ -771,38 +659,4 @@ fts_maxarglen(char * const *argv)
 	return (max + 1);
 }
 
-/*
- * Change to dir specified by fd or p->fts_accpath without getting
- * tricked by someone changing the world out from underneath us.
- * Assumes p->fts_dev and p->fts_ino are filled in.
- */
-static int
-fts_safe_changedir(FTS *sp, FTSENT *p, int fd, const char *path)
-{
-	int ret, oerrno, newfd;
-	struct stat sb;
-
-	newfd = fd;
-	if (ISSET(FTS_NOCHDIR))
-		return (0);
-	if (fd < 0 && (newfd = open(path, O_RDONLY|O_DIRECTORY|O_CLOEXEC)) < 0)
-		return (-1);
-	if (fstat(newfd, &sb)) {
-		ret = -1;
-		goto bail;
-	}
-	if (p->fts_dev != sb.st_dev || p->fts_ino != sb.st_ino) {
-		errno = ENOENT;		/* disinformation */
-		ret = -1;
-		goto bail;
-	}
-	ret = fchdir(newfd);
-bail:
-	oerrno = errno;
-	if (fd < 0)
-		(void)close(newfd);
-	errno = oerrno;
-	return (ret);
-}
-
 #endif
