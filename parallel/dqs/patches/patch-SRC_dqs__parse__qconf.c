$NetBSD: patch-SRC_dqs__parse__qconf.c,v 1.1 2013/03/28 21:37:23 joerg Exp $

--- SRC/dqs_parse_qconf.c.orig	2013-03-28 16:17:09.000000000 +0000
+++ SRC/dqs_parse_qconf.c
@@ -1200,11 +1200,7 @@ dqs_list_type *dqs_parse_qconf(argv_head
 }
 
 /***********************************************************************/
-void *dqs_parse_destination_id_list(head,cp,opt)
-     dqs_list_type **head;
-     char          *cp;
-     int           opt;
-     
+void dqs_parse_destination_id_list(dqs_list_type **head, char *cp, int opt)
 {
   
   dqs_list_type listel;
