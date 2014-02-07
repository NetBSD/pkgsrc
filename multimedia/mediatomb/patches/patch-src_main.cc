$NetBSD: patch-src_main.cc,v 1.1 2014/02/07 14:25:15 wiedi Exp $

remove broken system check
--- src/main.cc.orig	2010-03-25 15:47:02.000000000 +0000
+++ src/main.cc
@@ -141,21 +141,6 @@ int main(int argc, char **argv, char **e
 
     Ref<Array<StringBase> > addFile(new Array<StringBase>());
 
-#ifdef SOLARIS
-    String ld_preload;
-    char *preload = getenv("LD_PRELOAD");
-    if (preload != NULL)
-        ld_preload = String(preload);
-
-    if ((preload == NULL) || (ld_preload.find("0@0") == -1))
-    {
-        printf("MediaTomb: Solaris check failed!\n");
-        printf("Please set the environment to match glibc behaviour!\n");
-        printf("LD_PRELOAD=/usr/lib/0@0.so.1\n");
-        exit(EXIT_FAILURE);
-    }
-#endif
-
 #ifdef HAVE_GETOPT_LONG   
     while (1)
     {
