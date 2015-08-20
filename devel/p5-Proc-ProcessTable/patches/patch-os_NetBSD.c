$NetBSD: patch-os_NetBSD.c,v 1.1 2015/08/20 15:38:37 wiz Exp $

Fix buffer overflow.
https://rt.cpan.org/Public/Bug/Display.html?id=106564

--- os/NetBSD.c.orig	2012-10-21 14:15:53.000000000 +0000
+++ os/NetBSD.c
@@ -60,7 +60,7 @@ void OS_get_table(){
 
   /* for bless_into_proc */
   struct procstat prs; 
-  static char format[F_LASTFIELD + 1];
+  static char format[F_LASTFIELD + 2];
   char cmndline[ARG_MAX];
 
   if( (procdir = opendir("/proc")) == NULL ){
