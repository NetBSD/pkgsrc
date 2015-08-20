$NetBSD: patch-agent_mibgroup_kernel__sunos5.h,v 1.1 2015/08/20 13:51:03 jperkin Exp $

Support Crossbow.

--- agent/mibgroup/kernel_sunos5.h.orig	2007-11-08 23:17:16.000000000 +0000
+++ agent/mibgroup/kernel_sunos5.h
@@ -176,17 +176,17 @@ extern          "C" {
 #endif
     void            init_kernel_sunos5(void);
 
-    int             getKstat(const char *statname, const char *varname,
+    int             getKstat(char *statname, char *varname,
                              void *value);
     int             getMibstat(mibgroup_e grid, void *resp,
                                size_t entrysize, req_e req_type,
                                int (*comp) (void *, void *), void *arg);
     int             Get_everything(void *, void *);
-    int             getKstatInt(const char *classname,
-                                const char *statname, const char *varname,
+    int             getKstatInt(char *classname,
+                                char *statname, char *varname,
                                 int *value);
 
-    int             getKstatString(const char *statname, const char *varname,
+    int             getKstatString(char *statname, char *varname,
                                    char *value, size_t value_len);
 
     int             solaris2_if_nametoindex(const char *, int);
