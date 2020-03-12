$NetBSD: patch-compat.h,v 1.2 2020/03/12 11:35:33 leot Exp $

- Solaris has paths.h but does not define all used _PATH_*.
  Backport commit 92ecd611f68663dfceb2494e637b3ebe51d3fd86 to address that:
   <https://github.com/tmux/tmux/commit/92ecd611f68663dfceb2494e637b3ebe51d3fd86>

- Handle the FNM_CASEFOLD extension.
  Shared upstream via:
   <https://github.com/tmux/tmux/pull/2020>

--- compat.h.orig	2020-03-12 11:24:29.222099235 +0000
+++ compat.h
@@ -61,12 +61,31 @@ void	warn(const char *, ...);
 void	warnx(const char *, ...);
 #endif
 
-#ifndef HAVE_PATHS_H
-#define	_PATH_BSHELL	"/bin/sh"
-#define	_PATH_TMP	"/tmp/"
+#ifdef HAVE_PATHS_H
+#include <paths.h>
+#endif
+
+#ifndef _PATH_BSHELL
+#define _PATH_BSHELL	"/bin/sh"
+#endif
+
+#ifndef _PATH_TMP
+#define _PATH_TMP	"/tmp/"
+#endif
+
+#ifndef _PATH_DEVNULL
 #define _PATH_DEVNULL	"/dev/null"
+#endif
+
+#ifndef _PATH_TTY
 #define _PATH_TTY	"/dev/tty"
+#endif
+
+#ifndef _PATH_DEV
 #define _PATH_DEV	"/dev/"
+#endif
+
+#ifndef _PATH_DEFPATH
 #define _PATH_DEFPATH	"/usr/bin:/bin"
 #endif
 
@@ -98,10 +117,6 @@ void	warnx(const char *, ...);
 #include "compat/bitstring.h"
 #endif
 
-#ifdef HAVE_PATHS_H
-#include <paths.h>
-#endif
-
 #ifdef HAVE_LIBUTIL_H
 #include <libutil.h>
 #endif
@@ -154,6 +154,14 @@ void	warnx(const char *, ...);
 #define O_DIRECTORY 0
 #endif
 
+#ifndef FNM_CASEFOLD
+#ifdef FNM_IGNORECASE
+#define FNM_CASEFOLD FNM_IGNORECASE
+#else
+#define FNM_CASEFOLD 0
+#endif
+#endif
+
 #ifndef INFTIM
 #define INFTIM -1
 #endif
