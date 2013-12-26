$NetBSD: patch-awk.h,v 1.1 2013/12/26 19:19:32 tron Exp $

Fix build problem with SunStudio compiler under Solaris. Patch taken
from here:

http://lists.gnu.org/archive/html/bug-gawk/2011-07/msg00008.html

--- awk.h.orig	2013-04-07 18:54:28.000000000 +0100
+++ awk.h	2013-12-26 19:03:34.000000000 +0000
@@ -69,7 +69,7 @@
 #endif /* LOCALEDIR */
 #endif
 
-#if !defined(__STDC__) || __STDC__ < 1
+#if !defined(__STDC__) || __STDC__ < 1 && !defined(__EXTENSIONS__)
 #error "gawk no longer supports non-C89 environments (no __STDC__ or __STDC__ < 1)"
 #endif
 
