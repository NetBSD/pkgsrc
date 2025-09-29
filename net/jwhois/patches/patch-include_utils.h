$NetBSD: patch-include_utils.h,v 1.1 2025/09/29 20:41:00 mrg Exp $

Add missing prototype for GCC 14.

--- include/utils.h.orig	2002-08-02 15:18:38.000000000 -0700
+++ include/utils.h	2025-09-25 12:14:43.444945886 -0700
@@ -28,6 +28,7 @@
 int split_host_from_query(struct s_whois_query *wq);
 int make_connect(const char *, int);
 int add_text_to_buffer(char **, const char *);
+void timeout_init(void);
 
 
 #endif
