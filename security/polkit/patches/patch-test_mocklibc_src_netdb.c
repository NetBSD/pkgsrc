$NetBSD: patch-test_mocklibc_src_netdb.c,v 1.1 2021/06/03 14:43:07 wiz Exp $

Darwin has setnetgrent.
SunOS has endnetgrent.

--- test/mocklibc/src/netdb.c.orig	2014-01-14 22:42:25.000000000 +0000
+++ test/mocklibc/src/netdb.c
@@ -36,6 +36,7 @@ static struct netgroup_iter global_iter;
 
 // REMEMBER: 1 means success, 0 means failure for netgroup methods
 
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DragonFly__)
 int setnetgrent(const char *netgroup) {
   if (!global_netgroup_head)
     global_netgroup_head = netgroup_parse_all();
@@ -50,11 +51,14 @@ int setnetgrent(const char *netgroup) {
   netgroup_iter_init(&global_iter, group);
   return 1;
 }
+#endif
 
+#ifndef __sun__
 void endnetgrent(void) {
   netgroup_free_all(global_netgroup_head);
   global_netgroup_head = NULL;
 }
+#endif
 
 int getnetgrent(char **host, char **user, char **domain) {
   if (!global_netgroup_head)
