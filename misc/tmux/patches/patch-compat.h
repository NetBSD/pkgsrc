$NetBSD: patch-compat.h,v 1.1 2020/01/23 10:09:35 jperkin Exp $

Handle the FNM_CASEFOLD extension.  tmux/tmux#2020.

--- compat.h.orig	2019-06-26 11:26:30.000000000 +0000
+++ compat.h
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
