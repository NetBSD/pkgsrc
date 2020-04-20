$NetBSD: patch-src_include_commonfuncs.h,v 1.1 2020/04/20 00:46:51 joerg Exp $

--- src/include/commonfuncs.h.orig	2020-04-19 23:21:50.091150267 +0000
+++ src/include/commonfuncs.h
@@ -15,7 +15,7 @@ extern int   path_cmp(char *dir1, char *
 extern int   path_to_fullpath(char* dest, char *srcdir);
 extern void  add_path_content(char *curdir, const char *cont, int vms_host=0);
 extern void  upper_path(char *curdir, int vms_host=0);
-extern char* get_first_content(const char *curdir, char *cont);
+extern const char* get_first_content(const char *curdir, char *cont);
 extern void  get_last_content(char *curdir, char *cont);
 extern void  get_last_and_rest_content(char* curdir, char* last, char* rest);
 extern void  str_swap(char *str1, char *str2);
