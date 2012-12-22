$NetBSD: patch-kadmin_dbutil_dump.c,v 1.1 2012/12/22 02:28:30 joerg Exp $

--- kadmin/dbutil/dump.c.orig	2012-12-21 21:08:47.000000000 +0000
+++ kadmin/dbutil/dump.c
@@ -1573,6 +1573,7 @@ process_k5beta_record(fname, kcontext, f
                 error++;
             }
             /* Read the key type */
+            tmpint1 = 0;
             if (!error && (fscanf(filep, "\t%d\t", &tmpint1) != 1)) {
                 try2read = read_key_type;
                 error++;
@@ -1605,6 +1606,7 @@ process_k5beta_record(fname, kcontext, f
             }
 
             /* Read principal attributes */
+            tmpint3 = 0;
             if (!error && (fscanf(filep,
                                   "\t%u\t%u\t%u\t%u\t%u\t%u\t%u\t%u\t%u\t%u\t",
                                   &tmpint1, &dbent->max_life,
