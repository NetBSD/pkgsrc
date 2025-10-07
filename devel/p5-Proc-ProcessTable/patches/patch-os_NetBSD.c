$NetBSD: patch-os_NetBSD.c,v 1.3 2025/10/07 08:52:54 wiz Exp $

Fix build with gcc 14.
https://github.com/jwbargsten/perl-proc-processtable/issues/40

--- os/NetBSD.c.orig	2025-10-07 08:49:45.262130326 +0000
+++ os/NetBSD.c
@@ -1,6 +1,8 @@
 
 #include "os/NetBSD.h"
 
+void bless_into_proc(char* , char**, ...);
+
 /* Given a path to a /proc/XXX/status file and a pointer to a procstat
    struct, fill the struct */
 struct procstat* get_procstat( char* path, struct procstat* prs){
