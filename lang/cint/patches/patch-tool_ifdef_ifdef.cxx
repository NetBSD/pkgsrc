$NetBSD: patch-tool_ifdef_ifdef.cxx,v 1.1 2016/09/28 10:00:27 kamil Exp $

Reuse getopt(3) prototype on BSDs from standard header.

--- tool/ifdef/ifdef.cxx.orig	2006-07-26 13:00:37.000000000 +0000
+++ tool/ifdef/ifdef.cxx
@@ -20,6 +20,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
+#include <unistd.h>
 #include <string>
 #include <map>
 #ifndef __hpux
@@ -69,7 +70,7 @@ extern "C" {
 char *G__calc(char*);
 char *G__getexpr(char*);
 char *G__getandor(char*);
-#if !defined(__hpux) && !defined(__APPLE__) 
+#if !defined(__hpux) && !defined(__APPLE__) && !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__DragonFly__)
 char getopt(int argc,char **argv,char *optlist);
 #endif
 extern int optind;
@@ -946,4 +947,3 @@ int G__splitawk(char* string,int* argc,c
   }
   return(n_eof);
 }
-
