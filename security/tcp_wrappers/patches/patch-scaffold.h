$NetBSD: patch-scaffold.h,v 1.1 2025/04/29 14:18:00 tnn Exp $

--- scaffold.h.orig	2025-04-29 13:27:24.805794093 +0000
+++ scaffold.h
@@ -4,6 +4,6 @@
   * Author: Wietse Venema, Eindhoven University of Technology, The Netherlands.
   */
 
-extern struct hostent *find_inet_addr();
-extern int check_dns();
-extern int check_path();
+extern struct hostent *find_inet_addr(char *);
+extern int check_dns(char *);
+extern int check_path(char *, struct stat *);
