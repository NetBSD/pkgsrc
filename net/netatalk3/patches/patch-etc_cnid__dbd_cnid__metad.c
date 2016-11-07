$NetBSD: patch-etc_cnid__dbd_cnid__metad.c,v 1.2 2016/11/07 12:46:52 christos Exp $

Since we don't block, always wait...

--- etc/cnid_dbd/cnid_metad.c.orig	2014-05-22 01:33:45.000000000 -0400
+++ etc/cnid_dbd/cnid_metad.c	2016-11-06 09:31:53.239252178 -0500
@@ -534,7 +534,7 @@
     while (1) {
         rqstfd = usockfd_check(srvfd, &set);
         /* Collect zombie processes and log what happened to them */
-        if (sigchild) while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
+        while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
             for (i = 0; i < maxvol; i++) {
                 if (srv[i].pid == pid) {
                     srv[i].pid = 0;
