$NetBSD: patch-sv.c,v 1.1 2025/05/31 19:22:30 wiz Exp $

https://github.com/Perl/perl5/issues/23010
https://github.com/Perl/perl5/commit/918bfff86ca8d6d4e4ec5b30994451e0bd74aba9.patch

--- sv.c.orig	2025-03-30 10:35:51.000000000 +0000
+++ sv.c
@@ -14013,15 +14013,6 @@ Perl_dirp_dup(pTHX_ DIR *const dp, CLONE
 {
     DIR *ret;
 
-#if defined(HAS_FCHDIR) && defined(HAS_TELLDIR) && defined(HAS_SEEKDIR)
-    DIR *pwd;
-    const Direntry_t *dirent;
-    char smallbuf[256]; /* XXX MAXPATHLEN, surely? */
-    char *name = NULL;
-    STRLEN len = 0;
-    long pos;
-#endif
-
     PERL_UNUSED_CONTEXT;
     PERL_ARGS_ASSERT_DIRP_DUP;
 
@@ -14033,89 +14024,13 @@ Perl_dirp_dup(pTHX_ DIR *const dp, CLONE
     if (ret)
         return ret;
 
-#if defined(HAS_FCHDIR) && defined(HAS_TELLDIR) && defined(HAS_SEEKDIR)
+#ifdef HAS_FDOPENDIR
 
     PERL_UNUSED_ARG(param);
 
-    /* create anew */
-
-    /* open the current directory (so we can switch back) */
-    if (!(pwd = PerlDir_open("."))) return (DIR *)NULL;
-
-    /* chdir to our dir handle and open the present working directory */
-    if (fchdir(my_dirfd(dp)) < 0 || !(ret = PerlDir_open("."))) {
-        PerlDir_close(pwd);
-        return (DIR *)NULL;
-    }
-    /* Now we should have two dir handles pointing to the same dir. */
-
-    /* Be nice to the calling code and chdir back to where we were. */
-    /* XXX If this fails, then what? */
-    PERL_UNUSED_RESULT(fchdir(my_dirfd(pwd)));
-
-    /* We have no need of the pwd handle any more. */
-    PerlDir_close(pwd);
-
-#ifdef DIRNAMLEN
-# define d_namlen(d) (d)->d_namlen
-#else
-# define d_namlen(d) strlen((d)->d_name)
-#endif
-    /* Iterate once through dp, to get the file name at the current posi-
-       tion. Then step back. */
-    pos = PerlDir_tell(dp);
-    if ((dirent = PerlDir_read(dp))) {
-        len = d_namlen(dirent);
-        if (len > sizeof(dirent->d_name) && sizeof(dirent->d_name) > PTRSIZE) {
-            /* If the len is somehow magically longer than the
-             * maximum length of the directory entry, even though
-             * we could fit it in a buffer, we could not copy it
-             * from the dirent.  Bail out. */
-            PerlDir_close(ret);
-            return (DIR*)NULL;
-        }
-        if (len <= sizeof smallbuf) name = smallbuf;
-        else Newx(name, len, char);
-        Move(dirent->d_name, name, len, char);
-    }
-    PerlDir_seek(dp, pos);
-
-    /* Iterate through the new dir handle, till we find a file with the
-       right name. */
-    if (!dirent) /* just before the end */
-        for(;;) {
-            pos = PerlDir_tell(ret);
-            if (PerlDir_read(ret)) continue; /* not there yet */
-            PerlDir_seek(ret, pos); /* step back */
-            break;
-        }
-    else {
-        const long pos0 = PerlDir_tell(ret);
-        for(;;) {
-            pos = PerlDir_tell(ret);
-            if ((dirent = PerlDir_read(ret))) {
-                if (len == (STRLEN)d_namlen(dirent)
-                    && memEQ(name, dirent->d_name, len)) {
-                    /* found it */
-                    PerlDir_seek(ret, pos); /* step back */
-                    break;
-                }
-                /* else we are not there yet; keep iterating */
-            }
-            else { /* This is not meant to happen. The best we can do is
-                      reset the iterator to the beginning. */
-                PerlDir_seek(ret, pos0);
-                break;
-            }
-        }
-    }
-#undef d_namlen
-
-    if (name && name != smallbuf)
-        Safefree(name);
-#endif
+    ret = fdopendir(dup(my_dirfd(dp)));
 
-#ifdef WIN32
+#elif defined(WIN32)
     ret = win32_dirp_dup(dp, param);
 #endif
 
