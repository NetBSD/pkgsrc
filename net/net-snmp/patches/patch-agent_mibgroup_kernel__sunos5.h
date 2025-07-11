$NetBSD: patch-agent_mibgroup_kernel__sunos5.h,v 1.2 2025/07/11 10:11:52 jperkin Exp $

Support Crossbow.
Integer conversion fixes.

--- agent/mibgroup/kernel_sunos5.h.orig	2023-08-15 20:32:01.000000000 +0000
+++ agent/mibgroup/kernel_sunos5.h
@@ -190,17 +190,17 @@ extern          "C" {
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
-                                int *value);
+    int             getKstatInt(char *classname,
+                                char *statname, char *varname,
+                                uintptr_t *value);
 
-    int             getKstatString(const char *statname, const char *varname,
+    int             getKstatString(char *statname, char *varname,
                                    char *value, size_t value_len);
 
     int             solaris2_if_nametoindex(const char *, int);
