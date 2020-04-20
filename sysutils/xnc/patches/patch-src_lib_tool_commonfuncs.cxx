$NetBSD: patch-src_lib_tool_commonfuncs.cxx,v 1.1 2020/04/20 00:46:51 joerg Exp $

--- src/lib/tool/commonfuncs.cxx.orig	2020-04-19 23:21:06.744870536 +0000
+++ src/lib/tool/commonfuncs.cxx
@@ -117,9 +117,9 @@ void   upper_path(char *curdir, int vms_
 }
 
 //Get first content of dirname
-char*   get_first_content(const char *curdir, char *cont)
+const char*   get_first_content(const char *curdir, char *cont)
 {
-        char *b=strchr(curdir,'/');
+        const char *b=strchr(curdir,'/');
         if(b)
           {
                   strncpy(cont,curdir,b-curdir);
