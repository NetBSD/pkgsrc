$NetBSD: patch-process.c,v 1.1.2.2 2025/05/16 14:14:45 maya Exp $

https://security.opensuse.org/2025/05/12/screen-security-issues.html

--- process.c.orig	2024-08-28 19:55:03.000000000 +0000
+++ process.c
@@ -117,7 +117,7 @@ char NullStr[] = "";
 struct plop plop_tab[MAX_PLOP_DEFS];
 
 #ifndef PTY_MODE
-#define PTY_MODE 0622
+#define PTY_MODE 0620
 #endif
 
 int TtyMode = PTY_MODE;
