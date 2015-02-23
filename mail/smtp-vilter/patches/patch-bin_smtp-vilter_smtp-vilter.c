$NetBSD: patch-bin_smtp-vilter_smtp-vilter.c,v 1.1 2015/02/23 18:25:09 joerg Exp $

--- bin/smtp-vilter/smtp-vilter.c.orig	2015-02-23 14:37:03.000000000 +0000
+++ bin/smtp-vilter/smtp-vilter.c
@@ -872,9 +872,10 @@ main(int argc, char *argv[])
 					time(&now);
 					if ((fp = fopen(statfile, "a")) !=
 					    NULL) {
-						fprintf(fp, "%ld\t%ld\t%u\t%u\t"
+						fprintf(fp, "%lld\t%lld\t%u\t%u\t"
 						    "%u\t%u\t%u\t%u\t%u\n",	
-						    stat_begin, now, n_conn,
+						    (long long)stat_begin,
+						    (long long)now, n_conn,
 						    n_aborts, n_msgs,
 						    n_virus, n_spam,
 						    n_unwanted, n_err);
