$NetBSD: patch-etc_cnid__dbd_cnid__metad.c,v 1.1 2014/06/11 11:03:57 hauke Exp $

--- etc/cnid_dbd/cnid_metad.c.orig	2014-01-27 07:37:46.000000000 +0000
+++ etc/cnid_dbd/cnid_metad.c
@@ -504,7 +504,7 @@ int main(int argc, char *argv[])
     while (1) {
         rqstfd = usockfd_check(srvfd, &set);
         /* Collect zombie processes and log what happened to them */
-        if (sigchild) while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
+        while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
             for (i = 0; i < maxvol; i++) {
                 if (srv[i].pid == pid) {
                     srv[i].pid = 0;
