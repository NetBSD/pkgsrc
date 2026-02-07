$NetBSD: patch-libinetutils_libinetutils.h,v 1.1 2026/02/07 09:53:47 vins Exp $

Add missing function prototypes for orcmd.

--- libinetutils/libinetutils.h.orig	2026-02-03 16:56:28.553375955 +0000
+++ libinetutils/libinetutils.h
@@ -42,6 +42,12 @@ struct if_nameindex *if_nameindex (void)
 void if_freenameindex (struct if_nameindex *ptr);
 #endif
 
+#ifdef WITH_ORCMD_AF
+ int orcmd(char **, u_int, const char *, const char *, const char *, int *);
+ int orcmd_af(char **, u_int, const char *, const char *, const char *,
+     int *, int);
+#endif
+
 extern const char *default_program_authors[];
 
 #define iu_argp_init(name, authors)				\
