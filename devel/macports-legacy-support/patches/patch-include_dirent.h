$NetBSD: patch-include_dirent.h,v 1.1 2023/11/15 15:23:13 nia Exp $

Fix 10.4 support.
https://github.com/macports/macports-legacy-support/pull/69

--- include/dirent.h.orig	2023-09-15 08:59:52.000000000 +0000
+++ include/dirent.h
@@ -22,64 +22,9 @@
 /* MP support header */
 #include "MacportsLegacySupport.h"
 
-/* Alter function names declared by <dirent.h> to get them out of the way */
-/* Note: These renamed names are non-functional */
-#if __MP_LEGACY_SUPPORT_FDOPENDIR__
-#define opendir __mpls_renamed_libc_opendir
-#define closedir __mpls_renamed_libc_closedir
-#define readdir __mpls_renamed_libc_readdir
-#define readdir_r __mpls_renamed_libc_readdir_r
-#define rewinddir __mpls_renamed_libc_rewinddir
-#define seekdir __mpls_renamed_libc_seekdir
-#define telldir __mpls_renamed_libc_telldir
-#endif
-
 /* Include the primary system dirent.h */
 #include_next <dirent.h>
 
-/* Remove the above macros to make way for the declarations below */
-#if __MP_LEGACY_SUPPORT_FDOPENDIR__
-#undef opendir
-#undef closedir
-#undef readdir
-#undef readdir_r
-#undef rewinddir
-#undef seekdir
-#undef telldir
-
-#ifndef __MPLS_ALIAS
-#  define __MPLS_ALIAS(sym) __DARWIN_ALIAS(sym)
-#endif
-
-/* Fallback to __DARWIN_ALIAS if the other variants are not defined (?) */
-/* Note: I don't know if this makes sense */
-#ifndef __MPLS_ALIAS_I
-#  ifdef __DARWIN_ALIAS_I
-#    define __MPLS_ALIAS_I(sym) __DARWIN_ALIAS_I(sym)
-#  else
-#    define __MPLS_ALIAS_I(sym) __DARWIN_ALIAS(sym)
-#  endif
-#endif
-
-#ifndef __MPLS_INODE64
-#  ifdef __DARWIN_INODE64
-#    define __MPLS_INODE64(sym) __DARWIN_INODE64(sym)
-#  else
-#    define __MPLS_INODE64(sym) __DARWIN_ALIAS(sym)
-#  endif
-#endif
-
-/* Declare alternative names for the underlying functions for use by the wrappers */
-/* Note: Each __MPLS_ALIAS* macro must match the corresponding __DARWIN_ALIAS* in system <dirent.h> */
-DIR *__mpls_libc_opendir(const char *name) __MPLS_ALIAS_I(opendir);
-int __mpls_libc_closedir(DIR *dir) __MPLS_ALIAS(closedir);
-struct dirent *__mpls_libc_readdir(DIR *dir) __MPLS_INODE64(readdir);
-int __mpls_libc_readdir_r(DIR *dir, struct dirent *entry, struct dirent **result) __MPLS_INODE64(readdir_r);
-void __mpls_libc_rewinddir(DIR *dir) __MPLS_ALIAS_I(rewinddir);
-void __mpls_libc_seekdir(DIR *dir, long loc) __MPLS_ALIAS_I(seekdir);
-long __mpls_libc_telldir(DIR *dir) __MPLS_ALIAS_I(telldir);
-#endif
-
 /* fdopendir */
 #if __MP_LEGACY_SUPPORT_FDOPENDIR__
 
@@ -89,14 +34,17 @@ struct __MPLS_DIR {
     DIR *__mpls_dir;
     int __mpls_dirfd;
 };
-
 #define DIR __MPLS_DIR
 
 __MP__BEGIN_DECLS
 
-extern DIR *fdopendir(int fd) __MPLS_ALIAS_I(fdopendir);
+#ifndef __DARWIN_ALIAS_I
+extern DIR *fdopendir(int fd) __DARWIN_ALIAS(fdopendir);
+#else
+extern DIR *fdopendir(int fd) __DARWIN_ALIAS_I(fdopendir);
+#endif
 
-/* Wrapper functions to support fdopendir */
+/* Wrapper functions/macros to support fdopendir */
 extern DIR *__mpls_opendir(const char *name);
 extern int __mpls_closedir(DIR *dir);
 extern struct dirent *__mpls_readdir(DIR *dir);
@@ -106,14 +54,31 @@ extern void __mpls_seekdir(DIR *dir, lon
 extern long __mpls_telldir(DIR *dir);
 extern int __mpls_dirfd(DIR *dir);
 
-/* Define the standard names to refer to LegacySupport's wrappers (via asm renaming) */
-DIR *opendir(const char *name) __asm("___mpls_opendir");
-int closedir(DIR *dir) __asm("___mpls_closedir");
-struct dirent *readdir(DIR *dir) __asm("___mpls_readdir");
-int readdir_r(DIR *dir, struct dirent *entry, struct dirent **result) __asm("___mpls_readdir_r");
-void rewinddir(DIR *dir) __asm("___mpls_rewinddir");
-void seekdir(DIR *dir, long loc) __asm("___mpls_seekdir");
-long telldir(DIR *dir) __asm("___mpls_telldir");
+#define opendir __mpls_opendir
+/*
+** Add params to closedir to avoid apparently triggering a mysterious
+** problem encountered when testing capnproto. But only do this in C++
+** for capnproto's benefit. It is unknown why this makes any difference.
+** It really shouldn't. It makes no sense. It's probably unrelated.
+** WARNING: This means that it's not possible to take the address of
+** closedir in C++ (which has also been seen in the wild (dyld)).
+** But it is possible in C code. This is pragmatic(?), but not ideal.
+*/
+#if defined(__cplusplus)
+#define closedir(dir) __mpls_closedir(dir)
+#else
+#define closedir __mpls_closedir
+#endif
+#define readdir __mpls_readdir
+#define readdir_r __mpls_readdir_r
+#define rewinddir __mpls_rewinddir
+/* Add params to seekdir in C++ to not clash with type std::ios_base::seekdir */
+#if defined(__cplusplus)
+#define seekdir(dir, loc) __mpls_seekdir((dir), (loc))
+#else
+#define seekdir __mpls_seekdir
+#endif
+#define telldir __mpls_telldir
 
 #ifndef __MP_LEGACY_SUPPORT_NO_DIRFD_MACRO
 #undef dirfd
