$NetBSD: patch-src_billard3d.c,v 1.1 2015/09/27 10:07:53 tnn Exp $

Don't use Linux specific getopt_long_only.

--- src/billard3d.c.orig	2012-01-02 19:23:49.000000000 +0000
+++ src/billard3d.c
@@ -7597,7 +7597,7 @@ int main( int argc, char *argv[] )
 
    /* config file */
    load_config( &confv, &confc, argv, argc );
-   while( ( act_option = getopt_long_only(confc, confv, "+", long_options, &option_index) ) >= 0){
+   while( ( act_option = getopt_long(confc, confv, "+", long_options, &option_index) ) >= 0){
        //fprintf(stderr,"processing option %d=%s\n",act_option,optarg);
        process_option(act_option);
    }
