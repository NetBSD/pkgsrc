$NetBSD: patch-tools_threadlibs.c,v 1.1 2016/12/03 03:09:26 marino Exp $

Support DragonFly.

--- tools/threadlibs.c.orig	2016-08-02 19:36:14 UTC
+++ tools/threadlibs.c
@@ -42,7 +42,7 @@ int main(void)
 #       ifdef GC_USE_DLOPEN_WRAP
           printf("-ldl ");
 #       endif
-#       if (__FREEBSD_version >= 500000)
+#       if (__FREEBSD_version >= 500000) || defined __DragonFly__
           printf("-lpthread\n");
 #       else
           printf("-pthread\n");
