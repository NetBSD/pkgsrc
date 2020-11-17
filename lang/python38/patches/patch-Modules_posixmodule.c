$NetBSD: patch-Modules_posixmodule.c,v 1.1 2020/11/17 19:33:15 sjmulder Exp $

Support for macOS 11 and Apple Silicon (ARM). Mostly backported from:
https://github.com/python/cpython/pull/22855

--- Modules/posixmodule.c.orig	2020-09-23 12:36:32.000000000 +0000
+++ Modules/posixmodule.c
@@ -8,20 +8,6 @@
    of the compiler used.  Different compilers define their own feature
    test macro, e.g. '_MSC_VER'. */
 
-
-
-#ifdef __APPLE__
-   /*
-    * Step 1 of support for weak-linking a number of symbols existing on
-    * OSX 10.4 and later, see the comment in the #ifdef __APPLE__ block
-    * at the end of this file for more information.
-    */
-#  pragma weak lchown
-#  pragma weak statvfs
-#  pragma weak fstatvfs
-
-#endif /* __APPLE__ */
-
 #define PY_SSIZE_T_CLEAN
 
 #include "Python.h"
@@ -53,6 +39,127 @@
 
 #include <stdio.h>  /* needed for ctermid() */
 
+/*
+ * A number of APIs are available on macOS from a certain macOS version.
+ * To support building with a new SDK while deploying to older versions
+ * the availability test is split into two:
+ *   - HAVE_<FUNCTION>:  The configure check for compile time availability
+ *   - HAVE_<FUNCTION>_RUNTIME: Runtime check for availability
+ *
+ * The latter is always true when not on macOS, or when using a compiler
+ * that does not support __has_builtin (older versions of Xcode).
+ *
+ * Due to compiler restrictions there is one valid use of HAVE_<FUNCTION>_RUNTIME:
+ *    if (HAVE_<FUNCTION>_RUNTIME) { ... }
+ *
+ * In mixing the test with other tests or using negations will result in compile
+ * errors.
+ */
+#if defined(__APPLE__)
+
+#if defined(__has_builtin) && __has_builtin(__builtin_available)
+#  define HAVE_FSTATAT_RUNTIME __builtin_available(macOS 10.10, iOS 8.0, *)
+#  define HAVE_FACCESSAT_RUNTIME __builtin_available(macOS 10.10, iOS 8.0, *)
+#  define HAVE_FCHMODAT_RUNTIME __builtin_available(macOS 10.10, iOS 8.0, *)
+#  define HAVE_FCHOWNAT_RUNTIME __builtin_available(macOS 10.10, iOS 8.0, *)
+#  define HAVE_LINKAT_RUNTIME __builtin_available(macOS 10.10, iOS 8.0, *)
+#  define HAVE_FDOPENDIR_RUNTIME __builtin_available(macOS 10.10, iOS 8.0, *)
+#  define HAVE_MKDIRAT_RUNTIME __builtin_available(macOS 10.10, iOS 8.0, *)
+#  define HAVE_RENAMEAT_RUNTIME __builtin_available(macOS 10.10, iOS 8.0, *)
+#  define HAVE_UNLINKAT_RUNTIME __builtin_available(macOS 10.10, iOS 8.0, *)
+#  define HAVE_OPENAT_RUNTIME __builtin_available(macOS 10.10, iOS 8.0, *)
+#  define HAVE_READLINKAT_RUNTIME __builtin_available(macOS 10.10, iOS 8.0, *)
+#  define HAVE_SYMLINKAT_RUNTIME __builtin_available(macOS 10.10, iOS 8.0, *)
+#  define HAVE_FUTIMENS_RUNTIME __builtin_available(macOS 10.13, iOS 11.0, tvOS 11.0, watchOS 4.0, *)
+#  define HAVE_UTIMENSAT_RUNTIME __builtin_available(macOS 10.13, iOS 11.0, tvOS 11.0, watchOS 4.0, *)
+#  define HAVE_PWRITEV_RUNTIME __builtin_available(macOS 11.0, iOS 14.0, tvOS 14.0, watchOS 7.0, *)
+
+#  define HAVE_POSIX_SPAWN_SETSID_RUNTIME __builtin_available(macOS 10.15, *)
+
+#else /* Xcode 8 or earlier */
+
+   /* __builtin_available is not present in these compilers, but
+    * some of the symbols might be weak linked (10.10 SDK or later
+    * deploying on 10.9.
+    *
+    * Fall back to the older style of availability checking for
+    * symbols introduced in macOS 10.10.
+    */
+
+#  ifdef HAVE_FSTATAT
+#    define HAVE_FSTATAT_RUNTIME (fstatat != NULL)
+#  endif
+
+#  ifdef HAVE_FACCESSAT
+#    define HAVE_FACCESSAT_RUNTIME (faccessat != NULL)
+#  endif
+
+#  ifdef HAVE_FCHMODAT
+#    define HAVE_FCHMODAT_RUNTIME (fchmodat != NULL)
+#  endif
+
+#  ifdef HAVE_FCHOWNAT
+#    define HAVE_FCHOWNAT_RUNTIME (fchownat != NULL)
+#  endif
+
+#  ifdef HAVE_LINKAT
+#    define HAVE_LINKAT_RUNTIME (linkat != NULL)
+#  endif
+
+#  ifdef HAVE_FDOPENDIR
+#    define HAVE_FDOPENDIR_RUNTIME (fdopendir != NULL)
+#  endif
+
+#  ifdef HAVE_MKDIRAT
+#    define HAVE_MKDIRAT_RUNTIME (mkdirat != NULL)
+#  endif
+
+#  ifdef HAVE_RENAMEAT
+#    define HAVE_RENAMEAT_RUNTIME (renameat != NULL)
+#  endif
+
+#  ifdef HAVE_UNLINKAT
+#    define HAVE_UNLINKAT_RUNTIME (unlinkat != NULL)
+#  endif
+
+#  ifdef HAVE_OPENAT
+#    define HAVE_OPENAT_RUNTIME (openat != NULL)
+#  endif
+
+#  ifdef HAVE_READLINKAT
+#    define HAVE_READLINKAT_RUNTIME (readlinkat != NULL)
+#  endif
+
+#  ifdef HAVE_SYMLINKAT
+#    define HAVE_SYMLINKAT_RUNTIME (symlinkat != NULL)
+#  endif
+
+#endif
+
+#ifdef HAVE_FUTIMESAT
+/* Some of the logic for weak linking depends on this assertion */
+# error "HAVE_FUTIMESAT unexpectedly defined"
+#endif
+
+#else
+#  define HAVE_FSTATAT_RUNTIME 1
+#  define HAVE_FACCESSAT_RUNTIME 1
+#  define HAVE_FCHMODAT_RUNTIME 1
+#  define HAVE_FCHOWNAT_RUNTIME 1
+#  define HAVE_LINKAT_RUNTIME 1
+#  define HAVE_FDOPENDIR_RUNTIME 1
+#  define HAVE_MKDIRAT_RUNTIME 1
+#  define HAVE_RENAMEAT_RUNTIME 1
+#  define HAVE_UNLINKAT_RUNTIME 1
+#  define HAVE_OPENAT_RUNTIME 1
+#  define HAVE_READLINKAT_RUNTIME 1
+#  define HAVE_SYMLINKAT_RUNTIME 1
+#  define HAVE_FUTIMENS_RUNTIME 1
+#  define HAVE_UTIMENSAT_RUNTIME 1
+#  define HAVE_PWRITEV_RUNTIME 1
+#endif
+
+
 #ifdef __cplusplus
 extern "C" {
 #endif
@@ -2235,6 +2342,10 @@ posix_do_stat(const char *function_name,
     STRUCT_STAT st;
     int result;
 
+#ifdef HAVE_FSTATAT
+    int fstatat_unavailable = 0;
+#endif
+
 #if !defined(MS_WINDOWS) && !defined(HAVE_FSTATAT) && !defined(HAVE_LSTAT)
     if (follow_symlinks_specified(function_name, follow_symlinks))
         return NULL;
@@ -2261,15 +2372,27 @@ posix_do_stat(const char *function_name,
     else
 #endif /* HAVE_LSTAT */
 #ifdef HAVE_FSTATAT
-    if ((dir_fd != DEFAULT_DIR_FD) || !follow_symlinks)
-        result = fstatat(dir_fd, path->narrow, &st,
+    if ((dir_fd != DEFAULT_DIR_FD) || !follow_symlinks) {
+        if (HAVE_FSTATAT_RUNTIME) {
+            result = fstatat(dir_fd, path->narrow, &st,
                          follow_symlinks ? 0 : AT_SYMLINK_NOFOLLOW);
-    else
+
+        } else {
+            fstatat_unavailable = 1;
+        }
+    } else
 #endif /* HAVE_FSTATAT */
         result = STAT(path->narrow, &st);
 #endif /* MS_WINDOWS */
     Py_END_ALLOW_THREADS
 
+#ifdef HAVE_FSTATAT
+    if (fstatat_unavailable) {
+        argument_unavailable_error("stat", "dir_fd");
+        return NULL;
+    }
+#endif
+
     if (result != 0) {
         return path_error(path);
     }
@@ -2692,6 +2815,10 @@ os_access_impl(PyObject *module, path_t 
     int result;
 #endif
 
+#ifdef HAVE_FACCESSAT
+    int faccessat_unavailable = 0;
+#endif
+
 #ifndef HAVE_FACCESSAT
     if (follow_symlinks_specified("access", follow_symlinks))
         return -1;
@@ -2726,17 +2853,40 @@ os_access_impl(PyObject *module, path_t 
     if ((dir_fd != DEFAULT_DIR_FD) ||
         effective_ids ||
         !follow_symlinks) {
-        int flags = 0;
-        if (!follow_symlinks)
-            flags |= AT_SYMLINK_NOFOLLOW;
-        if (effective_ids)
-            flags |= AT_EACCESS;
-        result = faccessat(dir_fd, path->narrow, mode, flags);
+
+        if (HAVE_FACCESSAT_RUNTIME) {
+            int flags = 0;
+            if (!follow_symlinks)
+                flags |= AT_SYMLINK_NOFOLLOW;
+            if (effective_ids)
+                flags |= AT_EACCESS;
+            result = faccessat(dir_fd, path->narrow, mode, flags);
+        } else {
+            faccessat_unavailable = 1;
+        }
     }
     else
 #endif
         result = access(path->narrow, mode);
     Py_END_ALLOW_THREADS
+
+#ifdef HAVE_FACCESSAT
+    if (faccessat_unavailable) {
+        if (dir_fd != DEFAULT_DIR_FD) {
+            argument_unavailable_error("access", "dir_fd");
+            return -1;
+        }
+        if (follow_symlinks_specified("access", follow_symlinks))
+            return -1;
+
+        if (effective_ids) {
+            argument_unavailable_error("access", "effective_ids");
+            return -1;
+        }
+        /* should be unreachable */
+        return -1;
+    }
+#endif
     return_value = !result;
 #endif
 
@@ -2923,6 +3073,7 @@ os_chmod_impl(PyObject *module, path_t *
 
 #ifdef HAVE_FCHMODAT
     int fchmodat_nofollow_unsupported = 0;
+    int fchmodat_unsupported = 0;
 #endif
 
 #if !(defined(HAVE_FCHMODAT) || defined(HAVE_LCHMOD))
@@ -2958,42 +3109,56 @@ os_chmod_impl(PyObject *module, path_t *
     if (path->fd != -1)
         result = fchmod(path->fd, mode);
     else
-#endif
+#endif /* HAVE_CHMOD */
 #ifdef HAVE_LCHMOD
     if ((!follow_symlinks) && (dir_fd == DEFAULT_DIR_FD))
         result = lchmod(path->narrow, mode);
     else
-#endif
+#endif /* HAVE_LCHMOD */
 #ifdef HAVE_FCHMODAT
     if ((dir_fd != DEFAULT_DIR_FD) || !follow_symlinks) {
-        /*
-         * fchmodat() doesn't currently support AT_SYMLINK_NOFOLLOW!
-         * The documentation specifically shows how to use it,
-         * and then says it isn't implemented yet.
-         * (true on linux with glibc 2.15, and openindiana 3.x)
-         *
-         * Once it is supported, os.chmod will automatically
-         * support dir_fd and follow_symlinks=False.  (Hopefully.)
-         * Until then, we need to be careful what exception we raise.
-         */
-        result = fchmodat(dir_fd, path->narrow, mode,
-                          follow_symlinks ? 0 : AT_SYMLINK_NOFOLLOW);
-        /*
-         * But wait!  We can't throw the exception without allowing threads,
-         * and we can't do that in this nested scope.  (Macro trickery, sigh.)
-         */
-        fchmodat_nofollow_unsupported =
-                         result &&
-                         ((errno == ENOTSUP) || (errno == EOPNOTSUPP)) &&
-                         !follow_symlinks;
+        if (HAVE_FCHMODAT_RUNTIME) {
+            /*
+             * fchmodat() doesn't currently support AT_SYMLINK_NOFOLLOW!
+             * The documentation specifically shows how to use it,
+             * and then says it isn't implemented yet.
+             * (true on linux with glibc 2.15, and openindiana 3.x)
+             *
+             * Once it is supported, os.chmod will automatically
+             * support dir_fd and follow_symlinks=False.  (Hopefully.)
+             * Until then, we need to be careful what exception we raise.
+             */
+            result = fchmodat(dir_fd, path->narrow, mode,
+                              follow_symlinks ? 0 : AT_SYMLINK_NOFOLLOW);
+            /*
+             * But wait!  We can't throw the exception without allowing threads,
+             * and we can't do that in this nested scope.  (Macro trickery, sigh.)
+             */
+            fchmodat_nofollow_unsupported =
+                             result &&
+                             ((errno == ENOTSUP) || (errno == EOPNOTSUPP)) &&
+                             !follow_symlinks;
+        } else {
+            fchmodat_unsupported = 1;
+            fchmodat_nofollow_unsupported = 1;
+
+            result = -1;
+        }
     }
     else
-#endif
+#endif /* HAVE_FHCMODAT */
         result = chmod(path->narrow, mode);
     Py_END_ALLOW_THREADS
 
     if (result) {
 #ifdef HAVE_FCHMODAT
+        if (fchmodat_unsupported) {
+            if (dir_fd != DEFAULT_DIR_FD) {
+                argument_unavailable_error("chmod", "dir_fd");
+                return NULL;
+            }
+        }
+
         if (fchmodat_nofollow_unsupported) {
             if (dir_fd != DEFAULT_DIR_FD)
                 dir_fd_and_follow_symlinks_invalid("chmod",
@@ -3003,10 +3168,10 @@ os_chmod_impl(PyObject *module, path_t *
             return NULL;
         }
         else
-#endif
+#endif /* HAVE_FCHMODAT */
         return path_error(path);
     }
-#endif
+#endif /* MS_WINDOWS */
 
     Py_RETURN_NONE;
 }
@@ -3294,6 +3459,10 @@ os_chown_impl(PyObject *module, path_t *
 {
     int result;
 
+#if defined(HAVE_FCHOWNAT)
+    int fchownat_unsupported = 0;
+#endif
+
 #if !(defined(HAVE_LCHOWN) || defined(HAVE_FCHOWNAT))
     if (follow_symlinks_specified("chown", follow_symlinks))
         return NULL;
@@ -3302,19 +3471,6 @@ os_chown_impl(PyObject *module, path_t *
         fd_and_follow_symlinks_invalid("chown", path->fd, follow_symlinks))
         return NULL;
 
-#ifdef __APPLE__
-    /*
-     * This is for Mac OS X 10.3, which doesn't have lchown.
-     * (But we still have an lchown symbol because of weak-linking.)
-     * It doesn't have fchownat either.  So there's no possibility
-     * of a graceful failover.
-     */
-    if ((!follow_symlinks) && (lchown == NULL)) {
-        follow_symlinks_specified("chown", follow_symlinks);
-        return NULL;
-    }
-#endif
-
     if (PySys_Audit("os.chown", "OIIi", path->object, uid, gid,
                     dir_fd == DEFAULT_DIR_FD ? -1 : dir_fd) < 0) {
         return NULL;
@@ -3332,14 +3488,28 @@ os_chown_impl(PyObject *module, path_t *
     else
 #endif
 #ifdef HAVE_FCHOWNAT
-    if ((dir_fd != DEFAULT_DIR_FD) || (!follow_symlinks))
+    if ((dir_fd != DEFAULT_DIR_FD) || (!follow_symlinks)) {
+      if (HAVE_FCHOWNAT_RUNTIME) {
         result = fchownat(dir_fd, path->narrow, uid, gid,
                           follow_symlinks ? 0 : AT_SYMLINK_NOFOLLOW);
-    else
+      } else {
+         fchownat_unsupported = 1;
+      }
+    } else
 #endif
         result = chown(path->narrow, uid, gid);
     Py_END_ALLOW_THREADS
 
+#ifdef HAVE_FCHOWNAT
+    if (fchownat_unsupported) {
+        /* This would be incorrect if the current platform
+         * doesn't support lchown.
+         */
+        argument_unavailable_error(NULL, "dir_fd");
+        return NULL;
+    }
+#endif
+
     if (result)
         return path_error(path);
 
@@ -3585,6 +3755,9 @@ os_link_impl(PyObject *module, path_t *s
 #else
     int result;
 #endif
+#if defined(HAVE_LINKAT)
+    int linkat_unavailable = 0;
+#endif
 
 #ifndef HAVE_LINKAT
     if ((src_dir_fd != DEFAULT_DIR_FD) || (dst_dir_fd != DEFAULT_DIR_FD)) {
@@ -3619,15 +3792,43 @@ os_link_impl(PyObject *module, path_t *s
 #ifdef HAVE_LINKAT
     if ((src_dir_fd != DEFAULT_DIR_FD) ||
         (dst_dir_fd != DEFAULT_DIR_FD) ||
-        (!follow_symlinks))
-        result = linkat(src_dir_fd, src->narrow,
-            dst_dir_fd, dst->narrow,
-            follow_symlinks ? AT_SYMLINK_FOLLOW : 0);
+        (!follow_symlinks)) {
+
+        if (HAVE_LINKAT_RUNTIME) {
+
+            result = linkat(src_dir_fd, src->narrow,
+                dst_dir_fd, dst->narrow,
+                follow_symlinks ? AT_SYMLINK_FOLLOW : 0);
+
+        }
+#ifdef __APPLE__
+        else {
+            if (src_dir_fd == DEFAULT_DIR_FD && dst_dir_fd == DEFAULT_DIR_FD) {
+                /* See issue 41355: This matches the behaviour of !HAVE_LINKAT */
+                result = link(src->narrow, dst->narrow);
+            } else {
+                linkat_unavailable = 1;
+            }
+        }
+#endif
+    }
     else
 #endif /* HAVE_LINKAT */
         result = link(src->narrow, dst->narrow);
     Py_END_ALLOW_THREADS
 
+#ifdef HAVE_LINKAT
+    if (linkat_unavailable) {
+        /* Either or both dir_fd arguments were specified */
+        if (src_dir_fd  != DEFAULT_DIR_FD) {
+            argument_unavailable_error("link", "src_dir_fd");
+        } else {
+            argument_unavailable_error("link", "dst_dir_fd");
+        }
+        return NULL;
+    }
+#endif
+
     if (result)
         return path_error2(src, dst);
 #endif /* MS_WINDOWS */
@@ -3750,6 +3951,7 @@ _posix_listdir(path_t *path, PyObject *l
     errno = 0;
 #ifdef HAVE_FDOPENDIR
     if (path->fd != -1) {
+      if (HAVE_FDOPENDIR_RUNTIME) {
         /* closedir() closes the FD, so we duplicate it */
         fd = _Py_dup(path->fd);
         if (fd == -1)
@@ -3760,6 +3962,11 @@ _posix_listdir(path_t *path, PyObject *l
         Py_BEGIN_ALLOW_THREADS
         dirp = fdopendir(fd);
         Py_END_ALLOW_THREADS
+      } else {
+        PyErr_SetString(PyExc_TypeError,
+            "listdir: path should be string, bytes, os.PathLike or None, not int");
+        return NULL;
+      }
     }
     else
 #endif
@@ -4077,6 +4284,9 @@ os_mkdir_impl(PyObject *module, path_t *
 /*[clinic end generated code: output=a70446903abe821f input=e965f68377e9b1ce]*/
 {
     int result;
+#ifdef HAVE_MKDIRAT
+    int mkdirat_unavailable = 0;
+#endif
 
     if (PySys_Audit("os.mkdir", "Oii", path->object, mode,
                     dir_fd == DEFAULT_DIR_FD ? -1 : dir_fd) < 0) {
@@ -4093,9 +4303,14 @@ os_mkdir_impl(PyObject *module, path_t *
 #else
     Py_BEGIN_ALLOW_THREADS
 #if HAVE_MKDIRAT
-    if (dir_fd != DEFAULT_DIR_FD)
+    if (dir_fd != DEFAULT_DIR_FD) {
+      if (HAVE_MKDIRAT_RUNTIME) {
         result = mkdirat(dir_fd, path->narrow, mode);
-    else
+
+      } else {
+        mkdirat_unavailable = 1;
+      }
+    } else
 #endif
 #if defined(__WATCOMC__) && !defined(__QNX__)
         result = mkdir(path->narrow);
@@ -4103,6 +4318,14 @@ os_mkdir_impl(PyObject *module, path_t *
         result = mkdir(path->narrow, mode);
 #endif
     Py_END_ALLOW_THREADS
+
+#if HAVE_MKDIRAT
+    if (mkdirat_unavailable) {
+        argument_unavailable_error(NULL, "dir_fd");
+        return NULL;
+    }
+#endif
+
     if (result < 0)
         return path_error(path);
 #endif /* MS_WINDOWS */
@@ -4212,6 +4435,10 @@ internal_rename(path_t *src, path_t *dst
     const char *function_name = is_replace ? "replace" : "rename";
     int dir_fd_specified;
 
+#ifdef HAVE_RENAMEAT
+    int renameat_unavailable = 0;
+#endif
+
 #ifdef MS_WINDOWS
     BOOL result;
     int flags = is_replace ? MOVEFILE_REPLACE_EXISTING : 0;
@@ -4251,13 +4478,25 @@ internal_rename(path_t *src, path_t *dst
 
     Py_BEGIN_ALLOW_THREADS
 #ifdef HAVE_RENAMEAT
-    if (dir_fd_specified)
-        result = renameat(src_dir_fd, src->narrow, dst_dir_fd, dst->narrow);
-    else
+    if (dir_fd_specified) {
+        if (HAVE_RENAMEAT_RUNTIME) {
+            result = renameat(src_dir_fd, src->narrow, dst_dir_fd, dst->narrow);
+        } else {
+            renameat_unavailable = 1;
+        }
+    } else
 #endif
     result = rename(src->narrow, dst->narrow);
     Py_END_ALLOW_THREADS
 
+
+#ifdef HAVE_RENAMEAT
+    if (renameat_unavailable) {
+        argument_unavailable_error(function_name, "src_dir_fd and dst_dir_fd");
+        return NULL;
+    }
+#endif
+
     if (result)
         return path_error2(src, dst);
 #endif
@@ -4333,6 +4572,9 @@ os_rmdir_impl(PyObject *module, path_t *
 /*[clinic end generated code: output=080eb54f506e8301 input=38c8b375ca34a7e2]*/
 {
     int result;
+#ifdef HAVE_UNLINKAT
+    int unlinkat_unavailable = 0;
+#endif
 
     if (PySys_Audit("os.rmdir", "Oi", path->object,
                     dir_fd == DEFAULT_DIR_FD ? -1 : dir_fd) < 0) {
@@ -4345,14 +4587,26 @@ os_rmdir_impl(PyObject *module, path_t *
     result = !RemoveDirectoryW(path->wide);
 #else
 #ifdef HAVE_UNLINKAT
-    if (dir_fd != DEFAULT_DIR_FD)
+    if (dir_fd != DEFAULT_DIR_FD) {
+      if (HAVE_UNLINKAT_RUNTIME) {
         result = unlinkat(dir_fd, path->narrow, AT_REMOVEDIR);
-    else
+      } else {
+        unlinkat_unavailable = 1;
+        result = -1;
+      }
+    } else
 #endif
         result = rmdir(path->narrow);
 #endif
     Py_END_ALLOW_THREADS
 
+#ifdef HAVE_UNLINKAT
+    if (unlinkat_unavailable) {
+        argument_unavailable_error("rmdir", "dir_fd");
+        return NULL;
+    }
+#endif
+
     if (result)
         return path_error(path);
 
@@ -4496,6 +4750,9 @@ os_unlink_impl(PyObject *module, path_t 
 /*[clinic end generated code: output=621797807b9963b1 input=d7bcde2b1b2a2552]*/
 {
     int result;
+#ifdef HAVE_UNLINKAT
+    int unlinkat_unavailable = 0;
+#endif
 
     if (PySys_Audit("os.remove", "Oi", path->object,
                     dir_fd == DEFAULT_DIR_FD ? -1 : dir_fd) < 0) {
@@ -4509,15 +4766,27 @@ os_unlink_impl(PyObject *module, path_t 
     result = !Py_DeleteFileW(path->wide);
 #else
 #ifdef HAVE_UNLINKAT
-    if (dir_fd != DEFAULT_DIR_FD)
+    if (dir_fd != DEFAULT_DIR_FD) {
+      if (HAVE_UNLINKAT_RUNTIME) {
+
         result = unlinkat(dir_fd, path->narrow, 0);
-    else
+      } else {
+        unlinkat_unavailable = 1;
+      }
+    } else
 #endif /* HAVE_UNLINKAT */
         result = unlink(path->narrow);
 #endif
     _Py_END_SUPPRESS_IPH
     Py_END_ALLOW_THREADS
 
+#ifdef HAVE_UNLINKAT
+    if (unlinkat_unavailable) {
+        argument_unavailable_error(NULL, "dir_fd");
+        return NULL;
+    }
+#endif
+
     if (result)
         return path_error(path);
 
@@ -4690,7 +4959,16 @@ typedef struct {
 static int
 utime_dir_fd(utime_t *ut, int dir_fd, const char *path, int follow_symlinks)
 {
-#ifdef HAVE_UTIMENSAT
+#if defined(__APPLE__) &&  defined(HAVE_UTIMENSAT)
+    if (HAVE_UTIMENSAT_RUNTIME) {
+        int flags = follow_symlinks ? 0 : AT_SYMLINK_NOFOLLOW;
+        UTIME_TO_TIMESPEC;
+        return utimensat(dir_fd, path, time, flags);
+    }  else {
+        errno = ENOSYS;
+        return -1;
+    }
+#elif defined(HAVE_UTIMENSAT)
     int flags = follow_symlinks ? 0 : AT_SYMLINK_NOFOLLOW;
     UTIME_TO_TIMESPEC;
     return utimensat(dir_fd, path, time, flags);
@@ -4717,11 +4995,30 @@ static int
 utime_fd(utime_t *ut, int fd)
 {
 #ifdef HAVE_FUTIMENS
+
+    if (HAVE_FUTIMENS_RUNTIME) {
+
     UTIME_TO_TIMESPEC;
     return futimens(fd, time);
-#else
+
+    } else
+#ifndef HAVE_FUTIMES
+    {
+        /* Not sure if this can happen */
+        PyErr_SetString(
+            PyExc_RuntimeError,
+            "neither futimens nor futimes are supported"
+            " on this system");
+        return -1;
+    }
+#endif
+
+#endif
+#ifdef HAVE_FUTIMES
+    {
     UTIME_TO_TIMEVAL;
     return futimes(fd, time);
+    }
 #endif
 }
 
@@ -4740,11 +5037,27 @@ static int
 utime_nofollow_symlinks(utime_t *ut, const char *path)
 {
 #ifdef HAVE_UTIMENSAT
-    UTIME_TO_TIMESPEC;
-    return utimensat(DEFAULT_DIR_FD, path, time, AT_SYMLINK_NOFOLLOW);
-#else
+    if (HAVE_UTIMENSAT_RUNTIME) {
+        UTIME_TO_TIMESPEC;
+        return utimensat(DEFAULT_DIR_FD, path, time, AT_SYMLINK_NOFOLLOW);
+    } else
+#ifndef HAVE_LUTIMES
+    {
+        /* Not sure if this can happen */
+        PyErr_SetString(
+            PyExc_RuntimeError,
+            "neither utimensat nor lutimes are supported"
+            " on this system");
+        return -1;
+    }
+#endif
+#endif
+
+#ifdef HAVE_LUTIMES
+    {
     UTIME_TO_TIMEVAL;
     return lutimes(path, time);
+    }
 #endif
 }
 
@@ -4755,7 +5068,15 @@ utime_nofollow_symlinks(utime_t *ut, con
 static int
 utime_default(utime_t *ut, const char *path)
 {
-#ifdef HAVE_UTIMENSAT
+#if defined(__APPLE__) && defined(HAVE_UTIMENSAT)
+    if (HAVE_UTIMENSAT_RUNTIME) {
+        UTIME_TO_TIMESPEC;
+        return utimensat(DEFAULT_DIR_FD, path, time, 0);
+    } else {
+        UTIME_TO_TIMEVAL;
+        return utimes(path, time);
+    }
+#elif defined(HAVE_UTIMENSAT)
     UTIME_TO_TIMESPEC;
     return utimensat(DEFAULT_DIR_FD, path, time, 0);
 #elif defined(HAVE_UTIMES)
@@ -4964,9 +5285,10 @@ os_utime_impl(PyObject *module, path_t *
 #endif
 
 #if defined(HAVE_FUTIMESAT) || defined(HAVE_UTIMENSAT)
-    if ((dir_fd != DEFAULT_DIR_FD) || (!follow_symlinks))
+    if ((dir_fd != DEFAULT_DIR_FD) || (!follow_symlinks)) {
         result = utime_dir_fd(&utime, dir_fd, path->narrow, follow_symlinks);
-    else
+
+    } else
 #endif
 
 #if defined(HAVE_FUTIMES) || defined(HAVE_FUTIMENS)
@@ -4979,6 +5301,14 @@ os_utime_impl(PyObject *module, path_t *
 
     Py_END_ALLOW_THREADS
 
+#if defined(__APPLE__) && defined(HAVE_UTIMENSAT)
+    /* See utime_dir_fd implementation */
+    if (result == -1 && errno == ENOSYS) {
+        argument_unavailable_error(NULL, "dir_fd");
+        return NULL;
+    }
+#endif
+
     if (result < 0) {
         /* see previous comment about not putting filename in error here */
         posix_error();
@@ -5377,6 +5707,9 @@ parse_posix_spawn_flags(const char *func
     }
 
     if (setsid) {
+#ifdef HAVE_POSIX_SPAWN_SETSID_RUNTIME
+        if (HAVE_POSIX_SPAWN_SETSID_RUNTIME) {
+#endif
 #ifdef POSIX_SPAWN_SETSID
         all_flags |= POSIX_SPAWN_SETSID;
 #elif defined(POSIX_SPAWN_SETSID_NP)
@@ -5385,6 +5718,14 @@ parse_posix_spawn_flags(const char *func
         argument_unavailable_error(func_name, "setsid");
         return -1;
 #endif
+
+#ifdef HAVE_POSIX_SPAWN_SETSID_RUNTIME
+        } else {
+            argument_unavailable_error(func_name, "setsid");
+            return -1;
+        }
+#endif /* HAVE_POSIX_SPAWN_SETSID_RUNTIME */
+
     }
 
    if (setsigmask) {
@@ -7931,16 +8272,30 @@ os_readlink_impl(PyObject *module, path_
 #if defined(HAVE_READLINK)
     char buffer[MAXPATHLEN+1];
     ssize_t length;
+#ifdef HAVE_READLINKAT
+    int readlinkat_unavailable = 0;
+#endif
 
     Py_BEGIN_ALLOW_THREADS
 #ifdef HAVE_READLINKAT
-    if (dir_fd != DEFAULT_DIR_FD)
-        length = readlinkat(dir_fd, path->narrow, buffer, MAXPATHLEN);
-    else
+    if (dir_fd != DEFAULT_DIR_FD) {
+        if (HAVE_READLINKAT_RUNTIME) {
+            length = readlinkat(dir_fd, path->narrow, buffer, MAXPATHLEN);
+        } else {
+            readlinkat_unavailable = 1;
+        }
+    } else
 #endif
         length = readlink(path->narrow, buffer, MAXPATHLEN);
     Py_END_ALLOW_THREADS
 
+#ifdef HAVE_READLINKAT
+    if (readlinkat_unavailable) {
+        argument_unavailable_error(NULL, "dir_fd");
+        return NULL;
+    }
+#endif
+
     if (length < 0) {
         return path_error(path);
     }
@@ -8136,6 +8491,9 @@ os_symlink_impl(PyObject *module, path_t
     static int windows_has_symlink_unprivileged_flag = TRUE;
 #else
     int result;
+#ifdef HAVE_SYMLINKAT
+    int symlinkat_unavailable = 0;
+#endif
 #endif
 
     if (PySys_Audit("os.symlink", "OOi", src->object, dst->object,
@@ -8198,14 +8556,25 @@ os_symlink_impl(PyObject *module, path_t
     }
 
     Py_BEGIN_ALLOW_THREADS
-#if HAVE_SYMLINKAT
-    if (dir_fd != DEFAULT_DIR_FD)
-        result = symlinkat(src->narrow, dir_fd, dst->narrow);
-    else
+#ifdef HAVE_SYMLINKAT
+    if (dir_fd != DEFAULT_DIR_FD) {
+        if (HAVE_SYMLINKAT_RUNTIME) {
+            result = symlinkat(src->narrow, dir_fd, dst->narrow);
+        } else {
+            symlinkat_unavailable = 1;
+        }
+    } else
 #endif
         result = symlink(src->narrow, dst->narrow);
     Py_END_ALLOW_THREADS
 
+#ifdef HAVE_SYMLINKAT
+    if (symlinkat_unavailable) {
+          argument_unavailable_error(NULL, "dir_fd");
+          return NULL;
+    }
+#endif
+
     if (result)
         return path_error2(src, dst);
 #endif
@@ -8477,6 +8846,9 @@ os_open_impl(PyObject *module, path_t *p
 {
     int fd;
     int async_err = 0;
+#ifdef HAVE_OPENAT
+    int openat_unavailable = 0;
+#endif
 
 #ifdef O_CLOEXEC
     int *atomic_flag_works = &_Py_open_cloexec_works;
@@ -8501,9 +8873,15 @@ os_open_impl(PyObject *module, path_t *p
         fd = _wopen(path->wide, flags, mode);
 #else
 #ifdef HAVE_OPENAT
-        if (dir_fd != DEFAULT_DIR_FD)
-            fd = openat(dir_fd, path->narrow, flags, mode);
-        else
+        if (dir_fd != DEFAULT_DIR_FD) {
+            if (HAVE_OPENAT_RUNTIME) {
+                fd = openat(dir_fd, path->narrow, flags, mode);
+
+            } else {
+                openat_unavailable = 1;
+                fd = -1;
+            }
+        } else
 #endif /* HAVE_OPENAT */
             fd = open(path->narrow, flags, mode);
 #endif /* !MS_WINDOWS */
@@ -8511,6 +8889,13 @@ os_open_impl(PyObject *module, path_t *p
     } while (fd < 0 && errno == EINTR && !(async_err = PyErr_CheckSignals()));
     _Py_END_SUPPRESS_IPH
 
+#ifdef HAVE_OPENAT
+    if (openat_unavailable) {
+        argument_unavailable_error(NULL, "dir_fd");
+        return -1;
+    }
+#endif
+
     if (fd < 0) {
         if (!async_err)
             PyErr_SetFromErrnoWithFilenameObject(PyExc_OSError, path->object);
@@ -9081,12 +9466,25 @@ os_preadv_impl(PyObject *module, int fd,
     } while (n < 0 && errno == EINTR && !(async_err = PyErr_CheckSignals()));
 #else
     do {
+#ifdef __APPLE__
+/* This entire function will be removed from the module dict when the API
+ * is not available.
+ */
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wunguarded-availability"
+#pragma clang diagnostic ignored "-Wunguarded-availability-new"
+#endif
         Py_BEGIN_ALLOW_THREADS
         _Py_BEGIN_SUPPRESS_IPH
         n = preadv(fd, iov, cnt, offset);
         _Py_END_SUPPRESS_IPH
         Py_END_ALLOW_THREADS
     } while (n < 0 && errno == EINTR && !(async_err = PyErr_CheckSignals()));
+
+#ifdef __APPLE__
+#pragma clang diagnostic pop
+#endif
+
 #endif
 
     iov_cleanup(iov, buf, cnt);
@@ -9651,6 +10049,15 @@ os_pwritev_impl(PyObject *module, int fd
         Py_END_ALLOW_THREADS
     } while (result < 0 && errno == EINTR && !(async_err = PyErr_CheckSignals()));
 #else
+
+#ifdef __APPLE__
+/* This entire function will be removed from the module dict when the API
+ * is not available.
+ */
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wunguarded-availability"
+#pragma clang diagnostic ignored "-Wunguarded-availability-new"
+#endif
     do {
         Py_BEGIN_ALLOW_THREADS
         _Py_BEGIN_SUPPRESS_IPH
@@ -9658,6 +10065,11 @@ os_pwritev_impl(PyObject *module, int fd
         _Py_END_SUPPRESS_IPH
         Py_END_ALLOW_THREADS
     } while (result < 0 && errno == EINTR && !(async_err = PyErr_CheckSignals()));
+
+#ifdef __APPLE__
+#pragma clang diagnostic pop
+#endif
+
 #endif
 
     iov_cleanup(iov, buf, cnt);
@@ -10553,13 +10965,6 @@ os_statvfs_impl(PyObject *module, path_t
     Py_BEGIN_ALLOW_THREADS
 #ifdef HAVE_FSTATVFS
     if (path->fd != -1) {
-#ifdef __APPLE__
-        /* handle weak-linking on Mac OS X 10.3 */
-        if (fstatvfs == NULL) {
-            fd_specified("statvfs", path->fd);
-            return NULL;
-        }
-#endif
         result = fstatvfs(path->fd, &st);
     }
     else
@@ -12617,12 +13022,16 @@ DirEntry_fetch_stat(DirEntry *self, int 
     const char *path = PyBytes_AS_STRING(ub);
     if (self->dir_fd != DEFAULT_DIR_FD) {
 #ifdef HAVE_FSTATAT
+      if (HAVE_FSTATAT_RUNTIME) {
         result = fstatat(self->dir_fd, path, &st,
                          follow_symlinks ? 0 : AT_SYMLINK_NOFOLLOW);
-#else
+      } else
+#endif /* HAVE_FSTATAT */
+      {
+        Py_DECREF(ub);
         PyErr_SetString(PyExc_NotImplementedError, "can't fetch stat");
         return NULL;
-#endif /* HAVE_FSTATAT */
+      }
     }
     else
 #endif
@@ -13428,6 +13837,7 @@ os_scandir_impl(PyObject *module, path_t
     errno = 0;
 #ifdef HAVE_FDOPENDIR
     if (path->fd != -1) {
+      if (HAVE_FDOPENDIR_RUNTIME) {
         /* closedir() closes the FD, so we duplicate it */
         fd = _Py_dup(path->fd);
         if (fd == -1)
@@ -13436,6 +13846,11 @@ os_scandir_impl(PyObject *module, path_t
         Py_BEGIN_ALLOW_THREADS
         iterator->dirp = fdopendir(fd);
         Py_END_ALLOW_THREADS
+      } else {
+        PyErr_SetString(PyExc_TypeError,
+            "scandir: path should be string, bytes, os.PathLike or None, not int");
+        return NULL;
+      }
     }
     else
 #endif
@@ -14425,137 +14840,210 @@ static struct PyModuleDef posixmodule = 
 };
 
 
-static const char * const have_functions[] = {
+
+#define PROBE(name, test) \
+   static int name(void)  \
+   {                      \
+      if (test) {        \
+          return 1;       \
+      } else {            \
+          return 0;       \
+      }                   \
+   }
+
+#ifdef HAVE_FSTATAT
+PROBE(probe_fstatat, HAVE_FSTATAT_RUNTIME)
+#endif
+
+#ifdef HAVE_FACCESSAT
+PROBE(probe_faccessat, HAVE_FACCESSAT_RUNTIME)
+#endif
+
+#ifdef HAVE_FCHMODAT
+PROBE(probe_fchmodat, HAVE_FCHMODAT_RUNTIME)
+#endif
+
+#ifdef HAVE_FCHOWNAT
+PROBE(probe_fchownat, HAVE_FCHOWNAT_RUNTIME)
+#endif
+
+#ifdef HAVE_LINKAT
+PROBE(probe_linkat, HAVE_LINKAT_RUNTIME)
+#endif
+
+#ifdef HAVE_FDOPENDIR
+PROBE(probe_fdopendir, HAVE_FDOPENDIR_RUNTIME)
+#endif
+
+#ifdef HAVE_MKDIRAT
+PROBE(probe_mkdirat, HAVE_MKDIRAT_RUNTIME)
+#endif
+
+#ifdef HAVE_RENAMEAT
+PROBE(probe_renameat, HAVE_RENAMEAT_RUNTIME)
+#endif
+
+#ifdef HAVE_UNLINKAT
+PROBE(probe_unlinkat, HAVE_UNLINKAT_RUNTIME)
+#endif
+
+#ifdef HAVE_OPENAT
+PROBE(probe_openat, HAVE_OPENAT_RUNTIME)
+#endif
+
+#ifdef HAVE_READLINKAT
+PROBE(probe_readlinkat, HAVE_READLINKAT_RUNTIME)
+#endif
+
+#ifdef HAVE_SYMLINKAT
+PROBE(probe_symlinkat, HAVE_SYMLINKAT_RUNTIME)
+#endif
+
+#ifdef HAVE_FUTIMENS
+PROBE(probe_futimens, HAVE_FUTIMENS_RUNTIME)
+#endif
+
+#ifdef HAVE_UTIMENSAT
+PROBE(probe_utimensat, HAVE_UTIMENSAT_RUNTIME)
+#endif
+
+
+
+
+static const struct have_function {
+    const char * const label;
+    int (*probe)(void);
+} have_functions[] = {
 
 #ifdef HAVE_FACCESSAT
-    "HAVE_FACCESSAT",
+    { "HAVE_FACCESSAT", probe_faccessat },
 #endif
 
 #ifdef HAVE_FCHDIR
-    "HAVE_FCHDIR",
+    { "HAVE_FCHDIR", NULL },
 #endif
 
 #ifdef HAVE_FCHMOD
-    "HAVE_FCHMOD",
+    { "HAVE_FCHMOD", NULL },
 #endif
 
 #ifdef HAVE_FCHMODAT
-    "HAVE_FCHMODAT",
+    { "HAVE_FCHMODAT", probe_fchmodat },
 #endif
 
 #ifdef HAVE_FCHOWN
-    "HAVE_FCHOWN",
+    { "HAVE_FCHOWN", NULL },
 #endif
 
 #ifdef HAVE_FCHOWNAT
-    "HAVE_FCHOWNAT",
+    { "HAVE_FCHOWNAT", probe_fchownat },
 #endif
 
 #ifdef HAVE_FEXECVE
-    "HAVE_FEXECVE",
+    { "HAVE_FEXECVE", NULL },
 #endif
 
 #ifdef HAVE_FDOPENDIR
-    "HAVE_FDOPENDIR",
+    { "HAVE_FDOPENDIR", probe_fdopendir },
 #endif
 
 #ifdef HAVE_FPATHCONF
-    "HAVE_FPATHCONF",
+    { "HAVE_FPATHCONF", NULL },
 #endif
 
 #ifdef HAVE_FSTATAT
-    "HAVE_FSTATAT",
+    { "HAVE_FSTATAT", probe_fstatat },
 #endif
 
 #ifdef HAVE_FSTATVFS
-    "HAVE_FSTATVFS",
+    { "HAVE_FSTATVFS", NULL },
 #endif
 
 #if defined HAVE_FTRUNCATE || defined MS_WINDOWS
-    "HAVE_FTRUNCATE",
+    { "HAVE_FTRUNCATE", NULL },
 #endif
 
 #ifdef HAVE_FUTIMENS
-    "HAVE_FUTIMENS",
+    { "HAVE_FUTIMENS", probe_futimens },
 #endif
 
 #ifdef HAVE_FUTIMES
-    "HAVE_FUTIMES",
+    { "HAVE_FUTIMES", NULL },
 #endif
 
 #ifdef HAVE_FUTIMESAT
-    "HAVE_FUTIMESAT",
+    { "HAVE_FUTIMESAT", NULL },
 #endif
 
 #ifdef HAVE_LINKAT
-    "HAVE_LINKAT",
+    { "HAVE_LINKAT", probe_linkat },
 #endif
 
 #ifdef HAVE_LCHFLAGS
-    "HAVE_LCHFLAGS",
+    { "HAVE_LCHFLAGS", NULL },
 #endif
 
 #ifdef HAVE_LCHMOD
-    "HAVE_LCHMOD",
+    { "HAVE_LCHMOD", NULL },
 #endif
 
 #ifdef HAVE_LCHOWN
-    "HAVE_LCHOWN",
+    { "HAVE_LCHOWN", NULL },
 #endif
 
 #ifdef HAVE_LSTAT
-    "HAVE_LSTAT",
+    { "HAVE_LSTAT", NULL },
 #endif
 
 #ifdef HAVE_LUTIMES
-    "HAVE_LUTIMES",
+    { "HAVE_LUTIMES", NULL },
 #endif
 
 #ifdef HAVE_MEMFD_CREATE
-    "HAVE_MEMFD_CREATE",
+    { "HAVE_MEMFD_CREATE", NULL },
 #endif
 
 #ifdef HAVE_MKDIRAT
-    "HAVE_MKDIRAT",
+    { "HAVE_MKDIRAT", probe_mkdirat },
 #endif
 
 #ifdef HAVE_MKFIFOAT
-    "HAVE_MKFIFOAT",
+    { "HAVE_MKFIFOAT", NULL },
 #endif
 
 #ifdef HAVE_MKNODAT
-    "HAVE_MKNODAT",
+    { "HAVE_MKNODAT", NULL },
 #endif
 
 #ifdef HAVE_OPENAT
-    "HAVE_OPENAT",
+    { "HAVE_OPENAT", probe_openat },
 #endif
 
 #ifdef HAVE_READLINKAT
-    "HAVE_READLINKAT",
+    { "HAVE_READLINKAT", probe_readlinkat },
 #endif
 
 #ifdef HAVE_RENAMEAT
-    "HAVE_RENAMEAT",
+    { "HAVE_RENAMEAT", probe_renameat },
 #endif
 
 #ifdef HAVE_SYMLINKAT
-    "HAVE_SYMLINKAT",
+    { "HAVE_SYMLINKAT", probe_symlinkat },
 #endif
 
 #ifdef HAVE_UNLINKAT
-    "HAVE_UNLINKAT",
+    { "HAVE_UNLINKAT", probe_unlinkat },
 #endif
 
 #ifdef HAVE_UTIMENSAT
-    "HAVE_UTIMENSAT",
+    { "HAVE_UTIMENSAT", probe_utimensat },
 #endif
 
 #ifdef MS_WINDOWS
-    "MS_WINDOWS",
+    { "MS_WINDOWS", NULL },
 #endif
 
-    NULL
+    { NULL, NULL }
 };
 
 
@@ -14564,12 +15052,28 @@ INITFUNC(void)
 {
     PyObject *m, *v;
     PyObject *list;
-    const char * const *trace;
 
     m = PyModule_Create(&posixmodule);
     if (m == NULL)
         return NULL;
 
+#if defined(HAVE_PWRITEV)
+    if (HAVE_PWRITEV_RUNTIME) {} else {
+        PyObject* dct = PyModule_GetDict(m);
+
+        if (dct == NULL) {
+            return NULL;
+        }
+
+        if (PyDict_DelItemString(dct, "pwritev") == -1) {
+            PyErr_Clear();
+        }
+        if (PyDict_DelItemString(dct, "preadv") == -1) {
+            PyErr_Clear();
+        }
+    }
+#endif
+
     /* Initialize environ dictionary */
     v = convertenviron();
     Py_XINCREF(v);
@@ -14676,44 +15180,6 @@ INITFUNC(void)
     }
     PyModule_AddObject(m, "uname_result", (PyObject *)UnameResultType);
 
-#ifdef __APPLE__
-    /*
-     * Step 2 of weak-linking support on Mac OS X.
-     *
-     * The code below removes functions that are not available on the
-     * currently active platform.
-     *
-     * This block allow one to use a python binary that was build on
-     * OSX 10.4 on OSX 10.3, without losing access to new APIs on
-     * OSX 10.4.
-     */
-#ifdef HAVE_FSTATVFS
-    if (fstatvfs == NULL) {
-        if (PyObject_DelAttrString(m, "fstatvfs") == -1) {
-            return NULL;
-        }
-    }
-#endif /* HAVE_FSTATVFS */
-
-#ifdef HAVE_STATVFS
-    if (statvfs == NULL) {
-        if (PyObject_DelAttrString(m, "statvfs") == -1) {
-            return NULL;
-        }
-    }
-#endif /* HAVE_STATVFS */
-
-# ifdef HAVE_LCHOWN
-    if (lchown == NULL) {
-        if (PyObject_DelAttrString(m, "lchown") == -1) {
-            return NULL;
-        }
-    }
-#endif /* HAVE_LCHOWN */
-
-
-#endif /* __APPLE__ */
-
     Py_INCREF(TerminalSizeType);
     PyModule_AddObject(m, "terminal_size", (PyObject*)TerminalSizeType);
 
@@ -14738,14 +15204,17 @@ INITFUNC(void)
     list = PyList_New(0);
     if (!list)
         return NULL;
-    for (trace = have_functions; *trace; trace++) {
-        PyObject *unicode = PyUnicode_DecodeASCII(*trace, strlen(*trace), NULL);
+    for (const struct have_function *trace = have_functions; trace->label; trace++) {
+        PyObject *unicode;
+        if (trace->probe && !trace->probe()) continue;
+        unicode = PyUnicode_DecodeASCII(trace->label, strlen(trace->label), NULL);
         if (!unicode)
             return NULL;
         if (PyList_Append(list, unicode))
             return NULL;
         Py_DECREF(unicode);
     }
+
     PyModule_AddObject(m, "_have_functions", list);
 
     Py_INCREF((PyObject *) &DirEntryType);
